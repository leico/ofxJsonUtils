//
//  bbb/json/parse.hpp
//
//  Created by ISHII 2bit on 2017/05/24.
//
//

#ifndef bbb_json_utils_parse_h
#define bbb_json_utils_parse_h

#include "./common.hpp"

namespace bbb {
    namespace json_utils {
        namespace detail {
            template <typename type>
            class is_json_loadable {
            private:
                template <typename testee, testee> struct really_has;
                template <typename checkee>
                static std::true_type test(really_has<void (checkee::*)(const bbb::json &), &checkee::load> *);
                template <typename>
                static std::false_type test(...);
                
            public:
                static bool const value = decltype(test<type>(0))::value;
            };
            
            void print_parse_error(const char * const header, const char * const error_str) {
                std::cerr << "[" << header << "] " << error_str << std::endl;
            }
        };
        
        template <typename type>
        static inline auto parse(const bbb::json &json, type &value)
        -> typename std::enable_if<json_utils::detail::is_json_loadable<type>::value>::type {
            value.load(json);
        }
        
        template <typename type>
        static inline void parse(const bbb::json &json, std::shared_ptr<type> &ptr) {
            ptr = ptr ? ptr : std::shared_ptr<type>(new type());
            parse(json, *(ptr.get()));
        }
    };
};

#endif /* bbb_json_utils_parse_hpp */
