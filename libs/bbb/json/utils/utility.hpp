//
//  bbb/json/utils/utility.hpp
//
//  Created by ISHII 2bit on 2017/05/24.
//
//

#ifndef bbb_json_utils_utility_hpp
#define bbb_json_utils_utility_hpp

#include <sstream>

#include "./common.hpp"

namespace bbb {
    namespace json_utils {
        static inline bbb::json parse(const std::string &json_str) {
            return bbb::json::parse(json_str);
        }
        
        static inline std::vector<bbb::json> parse_ndjson(const std::string &ndjson_str) {
            const char delim('\n');
            std::istringstream is(ndjson_str);
            std::vector<bbb::json> result;
            
            std::string field;
            while(std::getline(is, field, delim)) {
                if(field.empty()) continue;
                result.push_back(bbb::json::parse(field));
            }
            return result;
        }

        /**
         * @fn
         *
         * create `bbb :: json` ( typically `ofJson` ) object from key and value,
         * if type can convert to `bbb :: json` object
         *
         * ### parameters
         *
         * @param[in]   &key    reference of a key name  
         * @param[out]  &value  reference of a value 
         *
         * @return created `bbb :: json` object 
         *
         * ### failed 
         *
         * when `type` could not convert to `bbb :: json`, this function generates error.
         * 
         */
        template <typename type>
        static inline bbb::json create(const std::string &key, const type &value) {
            bbb::json json = bbb::json::object();
            json[key] = convert(value);
            return json;
        }
       
        /**
         * @fn
         *
         * create multi key `bbb :: json` object, see bbb :: json_utils :: create( const std :: string &key, const type &value )
         *
         * ### parameters
         *
         * @param[in]   &key    same as bbb :: json_utils :: create( const std :: string &key, const type &value )
         * @param[in]   &value  same as bbb :: json_utils :: create( const std :: string &key, const type &value )
         *
         * @param[in]   &others reference of pairs of key and value which you would add `bbb :: json` object
         *
         * @return same as bbb :: json_utils :: create( const std :: string &key, const type &value )
         *
         * ### failed
         *
         * same as bbb :: json_utils :: create( const std :: string &key, const type &value )
         * additionaly, this function failed if arguments are not paired.
         *
         */
        template <typename type, typename ... others>
        static inline auto create(const std::string &key, const type &value, const others & ... args)
        -> typename std::enable_if<2 <= sizeof...(others) && sizeof...(others) % 2 == 0, bbb::json>::type
        {
            bbb::json json = create(args ...);
            json[key] = convert(value);
            return json;
        }

        /**
         * @fn
         *
         * load value from `bbb :: json` (typically ofJson) object
         *
         * ### parameters
         *
         * @param[in]   &json   reference of a `bbb :: json` object
         * @param[in]   &key    reference of a key name
         * @param[out]  &value  reference of a variable, stored key value
         *
         * @return none
         *
         * ### failed
         *
         * when `type` could not convert to `bbb :: json`, this function generates error.
         *
         */
        template <typename type>
        static inline void load(const bbb::json &json, const std::string &key, type &value) {
            if(json.find(key) == json.end()) {
                std::cerr << "[bbb::json_utils::load] " << "skip " << key << ". is null" << std::endl;
            } else {
                parse(json[key], value);
            }
        }

        /**
         * @fn
         *
         * load multi value from `bbb :: json` (typically ofJson) object, see bbb :: json_utils :: load( const bbb :: json &json, const std :: string &key, type &value )
         *
         * ### parameters
         *
         * @param[in]   &json   same as bbb :: json_utils :: load( const bbb :: json &json, const std :: string &key, type &value )
         * @param[in]   &key    same as bbb :: json_utils :: load( const bbb :: json &json, const std :: string &key, type &value )
         * @param[out]  &value  same as bbb :: json_utils :: load( const bbb :: json &json, const std :: string &key, type &value )
         *
         * @param   &&others rhs reference of pairs of &key[in] and &value[out]
         *
         * @return none
         *
         * ### failed
         *
         * same as bbb :: json_utils :: load( const bbb :: json &json, const std :: string &key, type &value )
         * additionaly, this function failed if arguments are not paired
         *
         */
        template <typename type, typename ... others>
        static inline auto load(const bbb::json &json, const std::string &key, type &value, others && ... args)
        -> typename std::enable_if<2 <= sizeof...(others) && sizeof...(others) % 2 == 0, void>::type {
            if(json.find(key) == json.end()) {
                std::cerr << "[ofxJsonUtils::load] " << "skip " << key << ". is null" << std::endl;
            } else {
                parse(json[key], value);
            }
            load(json, std::forward<others>(args) ...);
        }

    };
};

#endif /* bbb_json_utils_utility_hpp */
