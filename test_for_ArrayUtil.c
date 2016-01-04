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
	printf("1 test is passed ----------------\n");
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
	printf("2 test is passed ----------------\n");
};

void test_for_resize_array_of_small_size(){
	ArrayUtil array = create(4,8);
	ArrayUtil resized_array = resize(array,6);
	int * base = (int *)resized_array.base;
	assert(resized_array.length == 6);
	printf("3 test is passed ----------------\n");
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
	printf("4 test is passed ----------------\n");
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
	printf("5 test passed -----------\n");
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
	printf("6 test passed -----------\n");

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
	printf("7 test passed -----------\n");
};


