#include<stdio.h>
int main(){
	int Pibo[68];
	int Case,Num;
	for (int i = 0; i < 68; ++i){
		if (i < 2)
			Pibo[i] = 1;
		else if (i == 2)
			Pibo[i] = 2;
		else if (i == 3)
			Pibo[i] = 4;
		else
			Pibo[i] = Pibo[i - 1] + Pibo[i - 2] + Pibo[i - 3] + Pibo[i - 4];
	}
	scanf("%d", &Case);
	while (Case--){
		scanf("%d", &Num);
		printf("%lld\n", Pibo[Num]);
	}
}