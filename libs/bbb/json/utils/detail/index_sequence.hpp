//
//  index_sequence.hpp
//
//  Created by ISHII 2bit on 2017/11/10.
//

#ifndef bbb_json_utils_detail_index_sequence_hpp
#define bbb_json_utils_detail_index_sequence_hpp

namespace bbb {
    namespace json_utils {
        namespace detail {
            template<std::size_t... indices>
            struct index_sequence
            {
                using type = index_sequence;
                using value_type = std::size_t;
                static constexpr std::size_t size() noexcept
                {
                    return sizeof...(indices);
                }
            };
            
            template<class seq1, class seq2>
            struct merge_and_renumber;
            
            template<std::size_t... indices1, std::size_t... indices2>
            struct merge_and_renumber<index_sequence<indices1 ...>, index_sequence<indices2 ...>>
            : index_sequence <indices1..., (sizeof...(indices1) + indices2)...>
            {};
            
            template<std::size_t n>
            struct make_index_sequence
            : merge_and_renumber <typename make_index_sequence<n / 2>::type, typename make_index_sequence<n - n / 2>::type>
            {};
            
            template<> struct make_index_sequence<0> : index_sequence<> {};
            template<> struct make_index_sequence<1> : index_sequence<0> {};
            
            template<typename... types>
            using index_sequence_for = make_index_sequence<sizeof...(types)>;
        };
    };
};

#endif /* bbb_json_utils_detail_index_sequence_hpp */
