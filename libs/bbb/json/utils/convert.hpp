//
//  bbb/json/convert.hpp
//
//  Created by ISHII 2bit on 2017/05/24.
//
//

#ifndef bbb_json_utils_convert_hpp
#define bbb_json_utils_convert_hpp

#include "./common.hpp"

namespace bbb {
    namespace json_utils {
        namespace detail {
            template <typename type>
            class is_json_encodable {
            private:
                template <typename testee, testee> struct really_has;
                template <typename checkee>
                static std::true_type test(really_has<bbb::json (checkee::*)() const, &checkee::to_json> *);
                template <typename checkee>
                static std::true_type test(really_has<bbb::json (checkee::*)(), &checkee::to_json> *);
                template <typename>
                static std::false_type test(...);

            public:
                static bool const value = decltype(test<type>(nullptr))::value;
            };
        };

        template <typename type>
        static inline auto convert(const type &value)
        -> typename std::enable_if<json_utils::detail::is_json_encodable<type>::value, bbb::json>::type
        {
            return value.to_json();
        }

        template <typename T>
        bbb::json inline convert(const std::shared_ptr<T> &ptr) {
            return ptr ? convert(*(ptr.get())) : bbb::json();
        }
    };
};

#endif /* bbb_json_utils_convert_hpp */
