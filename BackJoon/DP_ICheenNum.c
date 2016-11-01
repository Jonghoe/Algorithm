#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tag_tail tail;
struct tag_tail{
	int zero;
	int one;
};
void InitTail(tail* t){
	t->one = 0;
	t->zero = 0;
}
void PasteTail(tail* dst,tail* src){
	dst->one = src->one;
	dst->zero = src->zero;
}
void NextTail(tail* dst, tail*src){
	dst->zero += src->zero + src->one;
	dst->one = src->zero;
}
int CalTail(tail*src){
	return src->zero + src->one;
}

int main(){
	int K,Len=0;
	char* bit;
	tail t1, t2 = { 0, 1 };
	scanf("%d", &K);
	while (K >= 0){
		PasteTail(&t1, &t2);
		InitTail(&t2);
		NextTail(&t2, &t1);
		K -= CalTail(&t1);
		++Len;
	}
	bit = (char*)malloc(sizeof(char)*Len);
	K += CalTail(&t1);
	for (int i = 0; i < K; ++i){

	}
	
}