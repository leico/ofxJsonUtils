//
//  ofxJsonConvertFunctions.h
//
//  Created by ISHII 2bit on 2016/05/19.
//
//

#pragma once

#include "ofMain.h"
#include "ofJson_compatible.h"

namespace bbb {
    namespace json_utils {
        namespace detail {
            template <typename T>
            class has_toJson_const {
            private:
                template <typename U, U> struct really_has;
                template <typename C>
                static std::true_type Test(really_has<ofJson (C::*)() const, &C::toJson> *);
                template <typename>
                static std::false_type Test(...);
                
            public:
                static constexpr bool value = decltype(Test<T>(nullptr))::value;
            };
            
            template <typename T>
            class has_toJson {
            private:
                template <typename U, U> struct really_has;
                template <typename C>
                static std::true_type Test(really_has<ofJson (C::*)() const, &C::toJson> *);
                template <typename C>
                static std::true_type Test(really_has<ofJson (C::*)(), &C::toJson> *);
                template <typename>
                static std::false_type Test(...);
                
            public:
                static constexpr bool value = decltype(Test<T>(nullptr))::value;
            };
        };
    };
};

static inline void to_json(ofJson &json, const ofVec2f &v) {
    json = {
        { "x", v.x },
        { "y", v.y }
    };
}

static inline void to_json(ofJson &json, const ofVec3f &v) {
    json = {
        { "x", v.x },
        { "y", v.y },
        { "z", v.z }
    };
}

static inline void to_json(ofJson &json, const ofVec4f &v) {
    json = {
        { "x", v.x },
        { "y", v.y },
        { "z", v.z },
        { "w", v.w }
    };
}

static inline void to_json(ofJson &json, const ofRectangle &rect) {
    json = {
        { "x", rect.x },
        { "y", rect.y },
        { "width", rect.width },
        { "height", rect.height }
    };
}

static inline void to_json(ofJson &json, const ofMatrix4x4 &mat) {
    json = {
        { "value0", mat._mat[0] },
        { "value1", mat._mat[1] },
        { "value2", mat._mat[2] },
        { "value3", mat._mat[3] },
    };
}

template <typename PixelType>
static inline void to_json(ofJson &json, const ofColor_<PixelType> &c) {
    json = {
        { "r", c.r },
        { "g", c.g },
        { "b", c.b },
        { "a", c.a }
    };
}

template <typename Type>
static inline auto to_json(ofJson &json, const Type &v)
-> typename std::enable_if<bbb::json_utils::detail::has_toJson_const<Type>::value>::type
{
    json = v.toJson();
}

template <typename Type>
static inline auto to_json(ofJson &json, Type &v)
-> typename std::enable_if<!bbb::json_utils::detail::has_toJson_const<Type>::value && bbb::json_utils::detail::has_toJson<Type>::value>::type
{
    json = v.toJson();
}

namespace ofx {
    namespace JsonUtils = bbb::json_utils;
};

#include "../libs/bbb/json/utils/convert.hpp"
