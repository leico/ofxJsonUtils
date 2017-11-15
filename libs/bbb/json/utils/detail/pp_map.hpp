//
//  pp_map.hpp
//
//  Created by ISHII 2bit on 2017/11/09.
//

#ifndef bbb_pp_map_hpp
#define bbb_pp_map_hpp

//const num = 32;
//const arr = [1];
//const res = [];
//res.push("#define BBB_FOR_" + 1 + "(F, ARG) F(ARG)");
//for(var i = 2; i <= num; i++) {
//    res.push("#define BBB_FOR_" + i + "(F, ARG, ...) F(ARG) BBB_FOR_" + (i - 1) + "(F, __VA_ARGS__)");
//    arr.push(i);
//}
//res.push("#define BBB_SELECT_FOR(" + arr.map(i => "ARG" + i).join(", ") + ", SELECTED_FOR) SELECTED_FOR");
//res.push("#define BBB_FOR(F, ...) BBB_SELECT_FOR(__VA_ARGS__, " + arr.map(i => "BBB_FOR_" + (arr.length - i + 1)).join(", ") + ")(__VA_ARGS__)");
//
//console.log(res.join("\n"));

#define BBB_PP_MAP_1(F, ARG) F(ARG)
#define BBB_PP_MAP_2(F, ARG, ...) F(ARG) BBB_PP_MAP_1(F, __VA_ARGS__)
#define BBB_PP_MAP_3(F, ARG, ...) F(ARG) BBB_PP_MAP_2(F, __VA_ARGS__)
#define BBB_PP_MAP_4(F, ARG, ...) F(ARG) BBB_PP_MAP_3(F, __VA_ARGS__)
#define BBB_PP_MAP_5(F, ARG, ...) F(ARG) BBB_PP_MAP_4(F, __VA_ARGS__)
#define BBB_PP_MAP_6(F, ARG, ...) F(ARG) BBB_PP_MAP_5(F, __VA_ARGS__)
#define BBB_PP_MAP_7(F, ARG, ...) F(ARG) BBB_PP_MAP_6(F, __VA_ARGS__)
#define BBB_PP_MAP_8(F, ARG, ...) F(ARG) BBB_PP_MAP_7(F, __VA_ARGS__)
#define BBB_PP_MAP_9(F, ARG, ...) F(ARG) BBB_PP_MAP_8(F, __VA_ARGS__)
#define BBB_PP_MAP_10(F, ARG, ...) F(ARG) BBB_PP_MAP_9(F, __VA_ARGS__)
#define BBB_PP_MAP_11(F, ARG, ...) F(ARG) BBB_PP_MAP_10(F, __VA_ARGS__)
#define BBB_PP_MAP_12(F, ARG, ...) F(ARG) BBB_PP_MAP_11(F, __VA_ARGS__)
#define BBB_PP_MAP_13(F, ARG, ...) F(ARG) BBB_PP_MAP_12(F, __VA_ARGS__)
#define BBB_PP_MAP_14(F, ARG, ...) F(ARG) BBB_PP_MAP_13(F, __VA_ARGS__)
#define BBB_PP_MAP_15(F, ARG, ...) F(ARG) BBB_PP_MAP_14(F, __VA_ARGS__)
#define BBB_PP_MAP_16(F, ARG, ...) F(ARG) BBB_PP_MAP_15(F, __VA_ARGS__)
#define BBB_PP_MAP_17(F, ARG, ...) F(ARG) BBB_PP_MAP_16(F, __VA_ARGS__)
#define BBB_PP_MAP_18(F, ARG, ...) F(ARG) BBB_PP_MAP_17(F, __VA_ARGS__)
#define BBB_PP_MAP_19(F, ARG, ...) F(ARG) BBB_PP_MAP_18(F, __VA_ARGS__)
#define BBB_PP_MAP_20(F, ARG, ...) F(ARG) BBB_PP_MAP_19(F, __VA_ARGS__)
#define BBB_PP_MAP_21(F, ARG, ...) F(ARG) BBB_PP_MAP_20(F, __VA_ARGS__)
#define BBB_PP_MAP_22(F, ARG, ...) F(ARG) BBB_PP_MAP_21(F, __VA_ARGS__)
#define BBB_PP_MAP_23(F, ARG, ...) F(ARG) BBB_PP_MAP_22(F, __VA_ARGS__)
#define BBB_PP_MAP_24(F, ARG, ...) F(ARG) BBB_PP_MAP_23(F, __VA_ARGS__)
#define BBB_PP_MAP_25(F, ARG, ...) F(ARG) BBB_PP_MAP_24(F, __VA_ARGS__)
#define BBB_PP_MAP_26(F, ARG, ...) F(ARG) BBB_PP_MAP_25(F, __VA_ARGS__)
#define BBB_PP_MAP_27(F, ARG, ...) F(ARG) BBB_PP_MAP_26(F, __VA_ARGS__)
#define BBB_PP_MAP_28(F, ARG, ...) F(ARG) BBB_PP_MAP_27(F, __VA_ARGS__)
#define BBB_PP_MAP_29(F, ARG, ...) F(ARG) BBB_PP_MAP_28(F, __VA_ARGS__)
#define BBB_PP_MAP_30(F, ARG, ...) F(ARG) BBB_PP_MAP_29(F, __VA_ARGS__)
#define BBB_PP_MAP_31(F, ARG, ...) F(ARG) BBB_PP_MAP_30(F, __VA_ARGS__)
#define BBB_PP_MAP_32(F, ARG, ...) F(ARG) BBB_PP_MAP_31(F, __VA_ARGS__)
#define BBB_PP_SELECT_MAP(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14, ARG15, ARG16, ARG17, ARG18, ARG19, ARG20, ARG21, ARG22, ARG23, ARG24, ARG25, ARG26, ARG27, ARG28, ARG29, ARG30, ARG31, ARG32, SELECTED_MAP, ...) SELECTED_MAP
#define BBB_PP_MAP(F, ...) BBB_PP_SELECT_MAP(__VA_ARGS__, BBB_PP_MAP_32, BBB_PP_MAP_31, BBB_PP_MAP_30, BBB_PP_MAP_29, BBB_PP_MAP_28, BBB_PP_MAP_27, BBB_PP_MAP_26, BBB_PP_MAP_25, BBB_PP_MAP_24, BBB_PP_MAP_23, BBB_PP_MAP_22, BBB_PP_MAP_21, BBB_PP_MAP_20, BBB_PP_MAP_19, BBB_PP_MAP_18, BBB_PP_MAP_17, BBB_PP_MAP_16, BBB_PP_MAP_15, BBB_PP_MAP_14, BBB_PP_MAP_13, BBB_PP_MAP_12, BBB_PP_MAP_11, BBB_PP_MAP_10, BBB_PP_MAP_9, BBB_PP_MAP_8, BBB_PP_MAP_7, BBB_PP_MAP_6, BBB_PP_MAP_5, BBB_PP_MAP_4, BBB_PP_MAP_3, BBB_PP_MAP_2, BBB_PP_MAP_1)(F, __VA_ARGS__)

#endif /* bbb_pp_map_hpp */
