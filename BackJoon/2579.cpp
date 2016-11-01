#include<stdio.h>
using namespace std;
typedef unsigned long long ull;
ull max(ull a, ull b, ull c){
	return a >= b ? ((a >= c) ? a : c) : ((b >= c) ? b : c);
}
int main(){
	ull DP[300];
	int Input[300];
	int Num,i;
	scanf("%d", &Num);
	for (i = Num-1; i >=0; --i)
		scanf("%d", &Input[i]);
	for (i = 0; i <= Num; ++i)
		DP[i] = 0;
	DP[0] = Input[0];
	DP[1] = DP[0] + Input[1];
	DP[2] = max(0, DP[1], Input[0] + Input[2]);
	for (i = 3; i < Num ; ++i)
		DP[i] = max(DP[i - 1], DP[i - 2] + Input[i], Input[i] + Input[i - 1] + DP[i - 3]);
	if (Num <= 2)
		printf("%d", Input[0]);
	else
		printf("%lld", DP[i-1]);
	return 0;
}