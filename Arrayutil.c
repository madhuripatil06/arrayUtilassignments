#include "Arrayutil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ArrayUtil create(int typeSize, int length){
	ArrayUtil new_array;
	new_array.base = calloc(length , typeSize);
	new_array.typeSize = typeSize;
	new_array.length = length;
	return new_array;
};

ArrayUtil resize(ArrayUtil util, int length){
	realloc(util.base, (length * util.typeSize))	;
	util.length = length;
	return util;
};


int areEqual(ArrayUtil a, ArrayUtil b){
	int result = memcmp(a.base,b.base,a.length*a.typeSize);
	if(result == 0 && a.typeSize == b.typeSize) return 1;
	return 0;
};

int findIndex(ArrayUtil util, void* element){
	void * base = util.base;
	for(int i = 0 ; i < util.length ; i++){
		int res = memcmp(base , element , util.typeSize);
		if(res == 0) return i;
		base += util.typeSize;
	};
	return -1;
};

void dispose(ArrayUtil util){
	free(util.base);
};

void * findFirst(ArrayUtil util, MatchFunc *match, void* hint){
	void * base = util.base;
	for(int i = 0 ; i < util.length ; i++){
		if(match(hint,base) == 1) return base;
		base += util.typeSize;
	};
	return NULL;
};

void * findLast(ArrayUtil util, MatchFunc *match, void* hint){
	util.base += ((util.length-1) * util.typeSize);
	void * base = util.base;
	for(int i = 0 ; i < util.length ; i++){
		if(match(hint,base) == 1) return base;
		base -= util.typeSize;
	};
	return NULL;
};


int count(ArrayUtil util, MatchFunc* match, void* hint){
	void * base = util.base;
	int count = 0;
	for(int i = 0 ; i < util.length ; i++){
		if(match(hint,base) == 1) count++;
		base += util.typeSize; 
	};
	return count;
};

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	void * base = util.base;
	int count = 0;
	for(int i = 0 ; i < util.length ; i++){
		if(match(hint,base) == 1 && count < maxItems){
			*destination = base;
			count++;
			destination += util.typeSize;
		}; 
		base += util.typeSize; 
	};
	return count;

	// destination in order;

	// destination -= util.typeSize*count;
	// for(int i = 0 ; i < count ; i++){
	// 	printf("%d\n",*((int*)*destination));
	// 	destination += util.typeSize;
	// }

	// destination in reverse order;
	
	// for(int i = 0 ; i < count ;i++){
	// 	printf("%d\n",*((int *)*(destination-util.typeSize)));
	// 	destination -= util.typeSize;
	// }
};


void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	void * base_of_source = source.base;
	void * base_of_destination = destination.base;
	for(int i = 0 ; i < source.length ; i++){
		convert(hint, base_of_source, base_of_destination);
		base_of_destination += (destination.typeSize); 
		base_of_source += (source.typeSize); 
	};
};

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
	void * base = util.base;
	for(int  i = 0 ; i < util.length ; i++){
		operation(hint , base);
		base += util.typeSize; 
	};
};

void* reduce(ArrayUtil util, ReducerFunc* reducer_function, void* hint, void* intialValue){
	void * previousItem = intialValue;
	for(int i = 0 ; i < util.length ; i++){
		reducer_function(hint, previousItem, util.base);
		util.base += util.typeSize;
	};
	return previousItem;
};
	