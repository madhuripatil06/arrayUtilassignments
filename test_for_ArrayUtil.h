#include <assert.h>
#include "Arrayutil.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	test_for_create_array();
	return 0;
}


void test_for_create_array(){
	ArrayUtil numbers = create(4,5);
	int * pointer_to_numbers = (int *)numbers.base;
	pointer_to_numbers[0] = 90;
	assert(numbers.typeSize == 4);
	assert(numbers.length == 5);
	printf("--------------------------------------");
};