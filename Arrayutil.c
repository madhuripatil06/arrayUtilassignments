#include "Arrayutil.h"
#include <stdlib.h>
#include <stdio.h>

ArrayUtil create(int typeSize, int length){
	ArrayUtil new_array;
	new_array.base = calloc(length , typeSize);
	new_array.typeSize = typeSize;
	new_array.length = length;
	return new_array;
};

ArrayUtil resize(ArrayUtil util, int length){
	ArrayUtil new_array;
	new_array.base = realloc(util.base, length);
	new_array.length = length;
	return new_array;
};


int areEqual(ArrayUtil a, ArrayUtil b){
	if(a.length == b.length && a.typeSize == b.typeSize){
		int * base1 = (int *)a.base;
		int *base2 = (int *)b.base;
		int count = 0;
		for(int i = 0 ; i < a.length ; i++){
			if(base1[i] != base2[i]) count++;
		}
		if(count == 0)
			return 1;
		return 0;
	}
	return 0;
};