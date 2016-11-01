#include<iostream>
using namespace std;
/*
	문제 명   : 소인수 분해
	문제 링크 : https://www.acmicpc.net/problem/11653
*/
int main(){
	int Num, Divde=2;
	cin >> Num;
	while (Num >1)
		if (Num % Divde == 0){
			cout << Divde << "\n";
			Num /= Divde;
		}
		else
			++Divde;
	return 0;
}