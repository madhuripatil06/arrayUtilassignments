#include <assert.h>
#include "Arrayutil.h"
#include <stdio.h>
#include <stdlib.h>

void test_for_create_array_of_numbers(){
	ArrayUtil numbers = create(4,8);
	int * base = (int *)numbers.base;
	for(int i = 0 ; i < numbers.length ; i++){
		assert(base[i] == 0);
	};
	base[0] = 90;
	base[1] = 45;
	assert(numbers.typeSize == 4);	
	assert(numbers.length == 8);
	int a = ((int *)numbers.base)[0];
	int b = ((int *)numbers.base)[1];
	assert(a == 90);
	assert(b == 45);
	printf("1 test is passed ------------ \n");
};

void test_for_create_array_of_char(){
	ArrayUtil chars = create(4,8);
	char * base = (char *)chars.base;
	for(int i = 0 ; i < chars.length ; i++){
		assert(base[i] == 0);
	}
	base[0] = 65;
	base[1] = 97;
	assert(chars.typeSize == 4);
	assert(chars.length == 8);
	char a = ((char *)chars.base)[0];
	char b = ((char *)chars.base)[1];
	assert(a == 'A');
	assert(b == 'a');
	printf("2 tests passed -------------- \n");
};

void test_for_resize_array_of_small_size(){
	ArrayUtil array = create(4,8);
	ArrayUtil resized_array = resize(array,6);
	int * base = (int *)resized_array.base;
	assert(resized_array.length == 6);
	printf("3 tests passed -------------- \n");
};

void test_for_resize_array_of_big_size(){
	ArrayUtil array = create(4,8);
	int * base = (int *)array.base;
	base[0] = 1;
	base[1] = 2;
	base[2] = 3;
	base[3] = 4;
	ArrayUtil resized_array = resize(array,16);
	int * base_of_resized = (int *)resized_array.base;
	assert(base_of_resized[0] == 1);
	assert(base_of_resized[3] == 4);
	printf("4 tests passed -------------- \n");
};


void test_for_are_equal(){
	ArrayUtil array1 = create(4,8);
	int * base = (int *)array1.base;
	base[0] = 1;
	base[1] = 2;
	base[2] = 3;
	base[3] = 4;
	ArrayUtil array2 = create(4,8);
	int * base1 = (int *)array2.base;
	base1[0] = 1;
	base1[1] = 2;
	base1[2] = 3;
	base1[3] = 4;
	int result = areEqual(array1,array2);
	assert(result == 1);
	printf("5 tests passed -------------- \n");
};

void test_for_not_equal(){
	ArrayUtil array1 = create(4,8);
	int * base = (int *)array1.base;
	base[0] = 1;
	base[1] = 2;
	base[2] = 3;
	base[3] = 4;
	ArrayUtil array2 = create(4,8);
	int * base1 = (int *)array2.base;
	base1[0] = 1;
	base1[1] = 2;
	base1[2] = 9;
	base1[3] = 4;
	int result = areEqual(array1,array2);
	assert(result == 0);
	printf("6 tests passed -------------- \n");

};

void test_for_char_equal(){
	ArrayUtil array1 = create(4,8);
	char * base = (char *)array1.base;
	base[0] = 'a';
	base[1] = 'b';
	base[2] = 'c';
	base[3] = 'd';
	ArrayUtil array2 = create(4,8);
	char * base1 = (char *)array2.base;
	base1[0] = 'a';
	base1[1] = 'b';
	base1[2] = 'c';
	base1[3] = 'd';
	int result = areEqual(array1,array2);
	assert(result == 1);
	printf("7 tests passed -------------- \n");
};

void test_for_find_index_if_it_is_there(){
	ArrayUtil util = create(4,2);
	int * base = (int *)util.base;
	base[0] = 45;
	base[1] = 23;
	int a = 23;
	int b = 45;
	int result = findIndex(util, &a);
	assert(result == 1);
	int first = findIndex(util,&b);
	assert(first == 0);
	printf("8 tests passed -------------- \n");
};

void test_for_find_index_if_it_is_char(){
	char r = 'a';
	ArrayUtil util1 = create(1,4);
	char * base_for_char = (char *)util1.base;
	base_for_char[0] = 'r';
	base_for_char[1] = 'A';
	base_for_char[2] = 'a';
	base_for_char[3] = 'p';
	int result_for_char = findIndex(util1,&r);
	assert(result_for_char == 2);
	printf("9 tests passed  ------------- \n");
};

void test_for_find_index_if_it_is_not_there(){
	ArrayUtil util = create(4,2);
	int * base = (int *)util.base;
	base[0] = 45;
	base[1] = 23;
	int a = 93;
	int result = findIndex(util, &a);
	assert(result == -1);
	printf("10 tests passed ------------- \n");
};

int is_23(void * nothing,void* num){
	return *((int*)num) == 23;
};

int is_divisible(void * hint , void * num){
	return *((int *)num) % *((int *)hint) == 0;
};

void test_for_find_first_if_it_is_there(){
	ArrayUtil util = create(4,4);
	int * base = (int *)util.base;
	base[0] = 45;
	base[1] = 23;
	base[2] = 23;
	base[3] = 27;
	int er = -999;
	void * hint = &er;
	int anwser = *((int *)findFirst(util,is_23,hint));
	assert(anwser == 23);
	printf("11 tests passed ------------- \n");
};

void test_for_find_first_if_it_is_not_there(){
	ArrayUtil util = create(4,4);
	int * base = (int *)util.base;
	base[0] = 45;
	base[1] = 93;
	base[2] = 73;
	base[3] = 27;
	int er = 'N';
	void * hint = &er;
	assert(findFirst(util,is_23,hint) == NULL);
	printf("12 tests passed ------------- \n");
};

void test_for_find_first_for_divisible_by(){
	ArrayUtil util = create(4,4);
	int * base = (int *)util.base;
	base[0] = 45;
	base[1] = 90;
	base[2] = 73;
	base[3] = 25;
	int er = 5;
	void * hint = &er;
	int ans = *((int *)findFirst(util,is_divisible,hint));
	assert(ans == 45);
	printf("13 tests passed ------------- \n");
};

void test_for_find_last_for_divisible_by(){
	ArrayUtil util = create(4,4);
	int * base = (int *)util.base;
	base[0] = 45;
	base[1] = 90;
	base[2] = 73;
	base[3] = 25;
	int er = 5;
	void * hint = &er;
	int ans = *((int *)findLast(util,is_divisible,hint));
	assert(ans == 25);
	printf("14 tests passed ------------- \n");
};

void test_for_find_count_for_divisible_by(){
	ArrayUtil util = create(4,4);
	int * base = (int *)util.base;
	base[0] = 45;
	base[1] = 90;
	base[2] = 73;
	base[3] = 25;
	int er = 5;
	void * hint = &er;
	int ans = count(util,is_divisible,hint);
	assert(ans == 3);
	printf("15 tests passed ------------- \n");
};

void test_for_find_count_for_divisible_by_if_it_is_absent(){
	ArrayUtil util = create(4,4);
	int * base = (int *)util.base;
	base[0] = 45;
	base[1] = 90;
	base[2] = 73;
	base[3] = 25;
	int er = 7;
	void * hint = &er;
	int ans = count(util,is_divisible,hint);
	assert(ans == 0);
	printf("16 tests passed ------------- \n");
};

void test_for_filter_for_divisible_by_if_it_is_present(){
	ArrayUtil destination = create(4,4);
	ArrayUtil pointer_destination = create(4,4);
	for(int  i = 0 ; i < pointer_destination.length ; i++){
		pointer_destination.base = &destination.base;
		destination.base += destination.typeSize;
		pointer_destination.base += pointer_destination.typeSize;
	};
	ArrayUtil util = create(4,4);
	int * base = (int *)util.base;
	base[0] = 45;
	base[1] = 90;
	base[2] = 73;
	base[3] = 25;
	int er = 5;
	void * hint = &er;
	int ans = filter(util,is_divisible,hint,pointer_destination.base,pointer_destination.length);
	assert(ans == 3);
	printf("17 tests passed ------------- \n");
};


void test_for_filter_for_divisible_by_if_it_is_absent(){
	ArrayUtil destination = create(4,4);
	ArrayUtil pointer_destination = create(4,4);
	for(int  i = 0 ; i < pointer_destination.length ; i++){
		pointer_destination.base = &destination.base;
		destination.base += destination.typeSize;
		pointer_destination.base += pointer_destination.typeSize;
	};
	ArrayUtil util = create(4,4);
	int * base = (int *)util.base;
	base[0] = 45;
	base[1] = 97;
	base[2] = 73;
	base[3] = 25;
	int er = 10;
	void * hint = &er;
	int ans = filter(util,is_divisible,hint,pointer_destination.base,pointer_destination.length);
	assert(ans == 0);
	printf("18 tests passed ------------- \n");
};

int is_vowel(void * hint , void * letter){
	for(int i = 0 ; i < 5 ; i ++){
		if(*((char *)hint) == *((char *)letter)) return 1;
		hint += 1; 
	};
	return 0;
};

void test_for_filter_of_the_vowels(){
	ArrayUtil destination = create(1,4);
	ArrayUtil pointer_destination = create(1,4);
	for(int  i = 0 ; i < pointer_destination.length ; i++){
		pointer_destination.base = &destination.base;
		destination.base += destination.typeSize;
		pointer_destination.base += pointer_destination.typeSize;
	};
	ArrayUtil util = create(1,4);
	char * base = (char *)util.base;
	base[0] = 'a';
	base[1] = 'e';
	base[2] = 'j';
	base[3] = 'p';
	ArrayUtil hint = create(1,5);
	char * hint_base = (char *)hint.base;
	hint_base[0] = 'a';
	hint_base[1] = 'e';
	hint_base[2] = 'i';
	hint_base[3] = 'o';
	hint_base[4] = 'u';
	int ans = filter(util,is_vowel,hint.base,pointer_destination.base,pointer_destination.length);
	assert(ans == 2);
	printf("19 tests passed -------------\n");
};

void add_num(void* hint, void* sourceItem, void* destinationItem){
	*((int *)destinationItem) = *((int *)sourceItem) + *((int *)hint);
};

void test_for_map_on_array_to_add_num(){
	ArrayUtil source = create(4,7);
	ArrayUtil destination = create(4,7);
	int * base = (int *)source.base;
	base[0] = 3;
	base[1] = 8;
	base[2] = 23;
	base[3] = 56;
	base[4] = 7;
	int hint = 2;
	map(source, destination, add_num, &hint);
	for(int i = 0 ; i < source.length ; i ++){
		int source_num = *((int *)source.base) + hint;
		int destination_num = *((int *)destination.base);
		assert( source_num == destination_num );
		destination.base += destination.typeSize;
		source.base += source.typeSize;
	};
	printf("20 tests passing ------------\n");
};

void multiply_hint(void* hint, void* item){
	*((int *)item) = (*((int *)item)) * (*((int *)hint));
};

void get_square(void * hint , void * item){
	*((int *)item) = (*((int *)item)) * (*((int *)item));
};

void test_for_forEach_function_on_array(){
	ArrayUtil util = create(4,8);
	int * base  = (int *)util.base;
	base[0] = 90;
	base[1] = 9;
	base[2] = 34;
	base[3] = 67;
	int hint  = 2 ; 
	forEach(util, multiply_hint , &hint);
	assert(base[0] == 180);
	assert(base[1] == 18);
	assert(base[2] == 68);
	assert(base[3] == 134);
	printf("21 tests passed -------------\n");
};

void test_for_forEach_function_on_array_for_get_square(){
	ArrayUtil util = create(4,8);
	int * base  = (int *)util.base;
	base[0] = 1;
	base[1] = 4;
	base[2] = 9;
	base[3] = 6;
	int hint  = 2 ; 
	forEach(util, get_square , &hint);
	assert(base[0] == 1);
	assert(base[1] == 16);
	assert(base[2] == 81);
	assert(base[3] == 36);
	printf("22 tests passed -------------\n");
};

