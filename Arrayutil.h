typedef struct {
	void * base;
	int typeSize;
	int length;
} ArrayUtil ;

ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil util, int length);
int areEqual(ArrayUtil a, ArrayUtil b);