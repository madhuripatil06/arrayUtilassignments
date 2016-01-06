#include "test_for_ArrayUtil.c"


int main(){
	test_for_create_array_of_numbers();
	test_for_create_array_of_char();
	test_for_resize_array_of_small_size();
	test_for_resize_array_of_big_size();
	test_for_are_equal();
	test_for_not_equal();
	test_for_char_equal();
	test_for_find_index_if_it_is_there();
	test_for_find_index_if_it_is_char();
	test_for_find_index_if_it_is_not_there();
	test_for_find_first_if_it_is_there();
	test_for_find_first_if_it_is_not_there();
	test_for_find_first_for_divisible_by();	
	test_for_find_last_for_divisible_by();
	test_for_find_count_for_divisible_by();
	test_for_find_count_for_divisible_by_if_it_is_absent();
	test_for_filter_for_divisible_by_if_it_is_present();
	test_for_filter_for_divisible_by_if_it_is_absent();
	test_for_filter_of_the_vowels();
	test_for_map_on_array_to_add_num();
	test_for_forEach_function_on_array();
	test_for_forEach_function_on_array_for_get_square();
	test_for_reduce_in_array();
	return 0;
}

