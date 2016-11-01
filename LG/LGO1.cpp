#include<stdio.h>
#include<math.h>
typedef unsigned long long ULL;
ULL cal2(ULL A){
	ULL Ret_V=0;
	for (int i = 0; i < 32; ++i)
		if ((A >> i )& 0x1 ==1)
			Ret_V++;
	return Ret_V;
}

ULL cal(ULL A, ULL  B, ULL* A1){ 
	ULL Ret_V = 0;
	ULL Value = 1;
	Ret_V += B - A;
	for (int i = 0; i < 62 &&B/(Value<<=1) >0; ++i){
		ULL _A = A / Value;
		ULL _B = B / Value;
		Ret_V += _B - _A;
	}
	return Ret_V;
}
void InitA1(ULL* A1){
	for (int i = 0; i < 62; ++i)
		A1[i] = (ULL)pow(2.0, i + 2) - 2;
}
int main(){
	FILE* IF;
	FILE* OF;
	ULL A1[62];
	int Case = 0;
	ULL Sum = 0;
	IF=fopen("input.txt", "r");
	OF=fopen("output.txt", "w");
	fscanf(IF, "%d", &Case);
	InitA1(A1);
	while (Case--){
		ULL a, b;
		Sum = 0;
		fscanf(IF, "%lld%lld", &a, &b);
		Sum = cal(a, b, A1);
		fprintf(OF,"%lld\n", Sum);
	}
	fclose(IF);
	fclose(OF);
	return 0;
}