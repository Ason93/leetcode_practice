cmake_minimum_required(VERSION 3.21)
# set(CMAKE_C_COMPILER "/usr/local/bin/gcc-10")
# set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-10")
# set(CMAKE_C_COMPILER_WORKS 1)
# set(CMAKE_CXX_COMPILER_WORKS 1)
# # set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(LEETCODE_PRACTICE)
set(CMAKE_CXX_FLAGS "-std=c++11 -O0 -Wall -g -ggdb")

# geek_time
#add_executable(4_median_of_two_sorted_arrays ${PROJECT_SOURCE_DIR}/src/geek_time/4_median_of_two_sorted_arrays.cpp)
#add_executable(subgraph_match ${PROJECT_SOURCE_DIR}/src/geek_time/subgraph_match.cpp)
add_executable(206_24_25_141_142_linked_list ${PROJECT_SOURCE_DIR}/src/geek_time/206_24_25_141_142_linked_list.cpp) # baidu
add_executable(20_valid_parentheses ${PROJECT_SOURCE_DIR}/src/geek_time/20_valid_parentheses.cpp)
add_executable(225_232_stack_queue ${PROJECT_SOURCE_DIR}/src/geek_time/225_232_stack_queue.cpp)
add_executable(703_kth_largest_element_in_a_stream ${PROJECT_SOURCE_DIR}/src/geek_time/703_kth_largest_element_in_a_stream.cpp)
add_executable(239_sliding_window_maximum ${PROJECT_SOURCE_DIR}/src/geek_time/239_sliding_window_maximum.cpp) # interview
add_executable(1_15_18_sum ${PROJECT_SOURCE_DIR}/src/geek_time/1_15_18_sum.cpp)
add_executable(146_lru_cache ${PROJECT_SOURCE_DIR}/src/geek_time/146_lru_cache.cpp)
add_executable(98_validate_binary_search_tree ${PROJECT_SOURCE_DIR}/src/geek_time/98_validate_binary_search_tree.cpp)
add_executable(235_236_lowest_common_ancestor_of_a_binary_tree ${PROJECT_SOURCE_DIR}/src/geek_time/235_236_lowest_common_ancestor_of_a_binary_tree.cpp)
add_executable(50_pow_x_n ${PROJECT_SOURCE_DIR}/src/geek_time/50_pow_x_n.cpp)
add_executable(169_majority_element ${PROJECT_SOURCE_DIR}/src/geek_time/169_majority_element.cpp)
add_executable(102_binary_tree_level_order_traveral ${PROJECT_SOURCE_DIR}/src/geek_time/102_binary_tree_level_order_traveral.cpp)
add_executable(104_111_max_min_depth_of_binary_tree ${PROJECT_SOURCE_DIR}/src/geek_time/104_111_max_min_depth_of_binary_tree.cpp)
add_executable(22_generate_parentheses ${PROJECT_SOURCE_DIR}/src/geek_time/22_generate_parentheses.cpp)
add_executable(51_52_n_queens ${PROJECT_SOURCE_DIR}/src/geek_time/51_52_n_queens.cpp)
add_executable(36_37_sudoku ${PROJECT_SOURCE_DIR}/src/geek_time/36_37_sudoku.cpp)
add_executable(69_sqrt ${PROJECT_SOURCE_DIR}/src/geek_time/69_sqrt.cpp)
add_executable(208_implement_trie ${PROJECT_SOURCE_DIR}/src/geek_time/208_implement_trie.cpp)
add_executable(79_212_word_search ${PROJECT_SOURCE_DIR}/src/geek_time/79_212_word_search.cpp)
add_executable(191_number_of_1_bits ${PROJECT_SOURCE_DIR}/src/geek_time/191_number_of_1_bits.cpp)
add_executable(231_power_of_two ${PROJECT_SOURCE_DIR}/src/geek_time/231_power_of_two.cpp)
add_executable(338_counting_bits ${PROJECT_SOURCE_DIR}/src/geek_time/338_counting_bits.cpp)
add_executable(70_climbing_stairs ${PROJECT_SOURCE_DIR}/src/geek_time/70_climbing_stairs.cpp)
add_executable(120_triangle ${PROJECT_SOURCE_DIR}/src/geek_time/120_triangle.cpp)
add_executable(121_122_123_188_309_714_stock ${PROJECT_SOURCE_DIR}/src/geek_time/121_122_123_188_309_714_stock.cpp)
add_executable(300_longest_increasing_subsequence ${PROJECT_SOURCE_DIR}/src/geek_time/300_longest_increasing_subsequence.cpp)
add_executable(322_coin_change ${PROJECT_SOURCE_DIR}/src/geek_time/322_coin_change.cpp)
add_executable(72_edit_distance ${PROJECT_SOURCE_DIR}/src/geek_time/72_edit_distance.cpp)
add_executable(200_547_number_of_islands_provinces ${PROJECT_SOURCE_DIR}/src/geek_time/200_547_number_of_islands_provinces.cpp)

# leetcode_75
add_executable(1480_running_sum_of_1d_array ${PROJECT_SOURCE_DIR}/src/leetcode_75/1480_running_sum_of_1d_array.cpp)
add_executable(724_find_pivot_index ${PROJECT_SOURCE_DIR}/src/leetcode_75/724_find_pivot_index.cpp)
add_executable(205_isomorphic_strings ${PROJECT_SOURCE_DIR}/src/leetcode_75/205_isomorphic_strings.cpp) # interview
add_executable(392_is_subsequence ${PROJECT_SOURCE_DIR}/src/leetcode_75/392_is_subsequence.cpp)
add_executable(21_merge_two_sorted_lists ${PROJECT_SOURCE_DIR}/src/leetcode_75/21_merge_two_sorted_lists.cpp) # interview
add_executable(206_reverve_linked_list ${PROJECT_SOURCE_DIR}/src/leetcode_75/206_reverve_linked_list.cpp) # interview
add_executable(876_middle_of_the_linked_list ${PROJECT_SOURCE_DIR}/src/leetcode_75/876_middle_of_the_linked_list.cpp) # interview
add_executable(142_linked_list_cycle_ii ${PROJECT_SOURCE_DIR}/src/leetcode_75/142_linked_list_cycle_ii.cpp) # interview
add_executable(121_best_time_to_buy_and_sell_stock ${PROJECT_SOURCE_DIR}/src/leetcode_75/121_best_time_to_buy_and_sell_stock.cpp)
add_executable(409_longest_palindrome ${PROJECT_SOURCE_DIR}/src/leetcode_75/409_longest_palindrome.cpp)
add_executable(589_n-ary_tree_preorder_traversal ${PROJECT_SOURCE_DIR}/src/leetcode_75/589_n-ary_tree_preorder_traversal.cpp) # interview
add_executable(102_binary_tree_level_order_traversal_2 ${PROJECT_SOURCE_DIR}/src/leetcode_75/102_binary_tree_level_order_traversal_2.cpp) # interview
add_executable(704_binary_search ${PROJECT_SOURCE_DIR}/src/leetcode_75/704_binary_search.cpp)
add_executable(278_first_bad_version ${PROJECT_SOURCE_DIR}/src/leetcode_75/278_first_bad_version.cpp)
add_executable(98_validate_binary_search_tree_2 ${PROJECT_SOURCE_DIR}/src/leetcode_75/98_validate_binary_search_tree_2.cpp) # interview
add_executable(235_lowest_common_ancestor_of_a_binary_search_tree_2 ${PROJECT_SOURCE_DIR}/src/leetcode_75/235_lowest_common_ancestor_of_a_binary_search_tree_2.cpp) # interview
add_executable(733_flood_fill ${PROJECT_SOURCE_DIR}/src/leetcode_75/733_flood_fill.cpp)
add_executable(200_number_of_islands ${PROJECT_SOURCE_DIR}/src/leetcode_75/200_number_of_islands.cpp) # interview, again
add_executable(509_fibonacci_number ${PROJECT_SOURCE_DIR}/src/leetcode_75/509_fibonacci_number.cpp)
add_executable(70_climbing_stairs_2 ${PROJECT_SOURCE_DIR}/src/leetcode_75/70_climbing_stairs_2.cpp)

# top_interview_questions
add_executable(5_longest_palindromic_substring ${PROJECT_SOURCE_DIR}/src/top_interview_questions/5_longest_palindromic_substring.cpp)
add_executable(7_reverse_interger ${PROJECT_SOURCE_DIR}/src/top_interview_questions/7_reverse_interger.cpp)
add_executable(8_string_to_integer_atoi ${PROJECT_SOURCE_DIR}/src/top_interview_questions/8_string_to_integer_atoi.cpp)
add_executable(10_regular_expression_matching ${PROJECT_SOURCE_DIR}/src/top_interview_questions/10_regular_expression_matching.cpp)
add_executable(11_container_with_most_water ${PROJECT_SOURCE_DIR}/src/top_interview_questions/11_container_with_most_water.cpp)
add_executable(13_roman_to_integer ${PROJECT_SOURCE_DIR}/src/top_interview_questions/13_roman_to_integer.cpp)
add_executable(14_longest_common_prefix ${PROJECT_SOURCE_DIR}/src/top_interview_questions/14_longest_common_prefix.cpp)
add_executable(17_letter_combinations_of_a_phone_number ${PROJECT_SOURCE_DIR}/src/top_interview_questions/17_letter_combinations_of_a_phone_number.cpp)
add_executable(19_remove_nth_node_from_end_of_list ${PROJECT_SOURCE_DIR}/src/top_interview_questions/19_remove_nth_node_from_end_of_list.cpp)
add_executable(23_merge_k_sorted_lists ${PROJECT_SOURCE_DIR}/src/top_interview_questions/23_merge_k_sorted_lists.cpp)
add_executable(26_remove_duplicates_from_sorted_array ${PROJECT_SOURCE_DIR}/src/top_interview_questions/26_remove_duplicates_from_sorted_array.cpp)
add_executable(28_implement_str ${PROJECT_SOURCE_DIR}/src/top_interview_questions/28_implement_str.cpp)
add_executable(29_devide_two_integers ${PROJECT_SOURCE_DIR}/src/top_interview_questions/29_devide_two_integers.cpp)
add_executable(30_search_in_rotated_sorted_array ${PROJECT_SOURCE_DIR}/src/top_interview_questions/30_search_in_rotated_sorted_array.cpp)
add_executable(34_find_first_and_last_position_of_element_in_sorted_array ${PROJECT_SOURCE_DIR}/src/top_interview_questions/34_find_first_and_last_position_of_element_in_sorted_array.cpp) # baidu
add_executable(38_count_and_say ${PROJECT_SOURCE_DIR}/src/top_interview_questions/38_count_and_say.cpp)
add_executable(41_first_missing_positive ${PROJECT_SOURCE_DIR}/src/top_interview_questions/41_first_missing_positive.cpp)
add_executable(42_trapping_rain_water ${PROJECT_SOURCE_DIR}/src/top_interview_questions/42_trapping_rain_water.cpp) # interview
add_executable(44_wildcard_matching ${PROJECT_SOURCE_DIR}/src/top_interview_questions/44_wildcard_matching.cpp) # again
add_executable(46_permutations ${PROJECT_SOURCE_DIR}/src/top_interview_questions/46_permutations.cpp) # interview
add_executable(48_rotate_image ${PROJECT_SOURCE_DIR}/src/top_interview_questions/48_rotate_image.cpp) # interview

# interview
# xilinx
add_executable(3_easy_cal_design ${PROJECT_SOURCE_DIR}/src/interview/xilinx/3_easy_cal_design.cpp)
# baidu
add_executable(take_bad_stairs ${PROJECT_SOURCE_DIR}/src/interview/baidu/take_bad_stairs.cpp)
add_executable(write_a_string ${PROJECT_SOURCE_DIR}/src/interview/baidu/write_a_string.cpp)
# bytedance
add_executable(convert_treenode_to_double_linked_list ${PROJECT_SOURCE_DIR}/src/interview/bytedance/convert_treenode_to_double_linked_list.cpp)
add_executable(kth_maximum_sum_combination_from_two_arrays ${PROJECT_SOURCE_DIR}/src/interview/bytedance/kth_maximum_sum_combination_from_two_arrays.cpp)
# nvidia
add_executable(526_beautiful_arrangement ${PROJECT_SOURCE_DIR}/src/interview/nvidia/526_beautiful_arrangement.cpp)
add_executable(university_career_fair ${PROJECT_SOURCE_DIR}/src/interview/nvidia/university_career_fair.cpp)
add_executable(super_stack ${PROJECT_SOURCE_DIR}/src/interview/nvidia/super_stack.cpp)
add_executable(node_distances ${PROJECT_SOURCE_DIR}/src/interview/nvidia/node_distances.cpp)
# alibaba
add_executable(shared_ptr ${PROJECT_SOURCE_DIR}/src/interview/alibaba/shared_ptr.cpp)
