//
//  ofxJsonUtils.h
//
//  Created by ISHII 2bit on 2016/05/19.
//
//

#pragma once

#include "ofMain.h"

#include "ofxJsonConvertFunctions.h"
#include "ofxJsonParseFunctions.h"

#include "../libs/bbb/json.hpp"
#include "ofJson_compatible.h"

namespace bbb {
    namespace json_utils {
        OF_DEPRECATED_MSG("ofxJsonUtils::loadFromFile() is deprecated, use ofLoadJson() instead.", static inline ofJson loadFromFile(const std::string &path, bool isInDataDir = true));

        static inline ofJson loadFromFile(const std::string &path, bool isInDataDir) {
            const ofBuffer buffer = ofBufferFromFile(isInDataDir ? ofToDataPath(path, true) : path);
            if(buffer.size() == 0) {
                ofLogWarning("ofxJsonUtils") << path << " not found or empty file";
                return ofJson();
            }
            return ofJson::parse(buffer.getText());
        }
        
        static inline std::vector<ofJson> ofxLoadNDJson(const std::string &path) {
            ofBuffer buffer = ofBufferFromFile(ofToDataPath(path, true));
            std::vector<ofJson> jsons;
            if(buffer.size() == 0) {
                ofLogWarning("ofxJsonUtils") << path << " not found or empty file";
                return jsons;
            }
            for(const auto &line : buffer.getLines()) {
                if(line.empty()) continue;
                jsons.emplace_back(std::move(ofJson::parse(line)));
            }
            return jsons;
        }

        OF_DEPRECATED_MSG("ofxJsonUtils::loadNDJsonFromFile() is deprecated, use ofxLoadNDJson() instead.", static inline std::vector<ofJson> loadNDJsonFromFile(const std::string &path, bool isInDataDir = true));
        
        static inline std::vector<ofJson> loadNDJsonFromFile(const std::string &path, bool isInDataDir) {
            return ofxLoadNDJson(path);
        }
        
        OF_DEPRECATED_MSG("ofxJsonUtils::writeToFile() is deprecated, use ofSaveJson() instead.", static inline bool writeToFile(const std::string &path, const ofJson &json, bool isInDataDir = true, int indent = -1));
        
        static inline bool writeToFile(const std::string &path, const ofJson &json, bool isInDataDir, int indent) {
            const std::string file_path = isInDataDir ? ofToDataPath(path, true) : path;
            ofBuffer buf;
            buf.append(json.dump(indent));
            return ofBufferToFile(path, buf);
        }
        
        static inline bool ofxSaveNDJson(const std::string &path, const std::vector<ofJson> &jsons) {
            const std::string file_path = ofToDataPath(path, true);
            ofBuffer buf;
            for(const auto &json : jsons) {
                buf.append(json.dump());
                buf.append("\n");
            }
            return ofBufferToFile(path, buf);
        }

        OF_DEPRECATED_MSG("ofxJsonUtils::writeToNDJsonFile() is deprecated, use ofxSaveNDJson() instead.", static inline bool writeToNDJsonFile(const std::string &path, const std::vector<ofJson> &jsons, bool isInDataDir = true, int indent = -1));
        
        static inline bool writeToNDJsonFile(const std::string &path, const std::vector<ofJson> &jsons, bool isInDataDir, int indent) {
            return ofxSaveNDJson(path, jsons);
        }
        
        OF_DEPRECATED_MSG("ofxJsonUtils::ofxJsonToFile() is deprecated, use ofxJsonUtils::writeToFile() instead.", static inline bool ofxJsonToFile(const std::string &path, const ofJson &json, bool isInDataDir = true, int indent = -1));
        
        static inline bool ofxJsonToFile(const std::string &path, const ofJson &json, bool isInDataDir, int indent)
        {
            return writeToFile(path, json, isInDataDir, indent);
        }
        
        static inline bool hasKey(const ofJson &json, const std::string &key) {
            return json.find(key) != json.end();
        }
        
        struct key_not_found_exception : public std::exception {
            key_not_found_exception(const std::string &message)
                : message(message) {}
            const std::string message;
            virtual const char* what() const noexcept override {
                return message.c_str();
            }
        };
        
        static inline void validationAssert(const ofJson &json,
                                            const std::string &key)
            throw(key_not_found_exception)
        {
            if(!hasKey(json, key)) {
                throw key_not_found_exception("json: \"" + key + "\" is not exists.");
            }
        }
        
        template <typename ... key_types>
        static inline void validationAssert(const ofJson &json,
                                            const std::string &key,
                                            key_types && ... keys)
        throw(key_not_found_exception)
        {
            validationAssert(json, key);
            validationAssert(json, std::forward<key_types>(keys) ...);
        }
    };
};

using bbb::json_utils::ofxLoadNDJson;
using bbb::json_utils::ofxSaveNDJson;

#include "ofxJsonify.h"
namespace ofxJsonUtils = bbb::json_utils;

#define OFX_JSONIZE(Class, ...)\
bbb::json toJson() const { bbb::json json; BBB_PP_MAP(BBB_PP_TO_JSON, __VA_ARGS__); return json; };\
void loadJson(const bbb::json &json) { BBB_PP_MAP(BBB_PP_FROM_JSON, __VA_ARGS__);};

#define kv(name) #name, name
