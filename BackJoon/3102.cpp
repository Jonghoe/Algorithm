#include<iostream>
using namespace std;
int Min=-1;
int Arr[1000001];
void Calculate(int Num,int Count){
	if (Num == 1){
		if (Min == -1)
			Min = Count;
		else if (Min > Count)
			Min = Count;
		return;
	}
	if (Num % 2 == 0)
		Calculate(Num / 2, Count + 1);

	if (Num % 3 == 0)
		Calculate(Num / 3, Count + 1);
	Calculate(Num - 1, Count + 1);
}
int main(){
	int Num;
	cin >> Num;
	for (int i = 0; i < Num; ++i){

	}
	Calculate(Num,0);
	cout << Min << endl;
	return 0;
}