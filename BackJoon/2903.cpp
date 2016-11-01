#include<iostream>
using namespace std;
#define MODULA 1000000000l
#define Prev(x) (((x)+1)%2)
#define CHANGE(x) (x)=(((x)+1)%2)
void Init(int* arr){
	arr[0] = 0;
	for (int i = 1; i < 10; ++i)
		arr[i] = 1;
}
int main(){
	int Num, Len = 0;
	int Sum = 0;
	int NumArr[2][10] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						  0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	
	cin >> Num;
	for (int i = 1; i < Num; ++i){
		CHANGE(Len);
		NumArr[Len][0] = NumArr[Prev(Len)][1] % MODULA;
		for (int j = 1; j < 9; ++j)
			NumArr[Len][j] = (NumArr[Prev(Len)][j - 1] +NumArr[Prev(Len)][j + 1]) % MODULA;
		NumArr[Len][9] = (NumArr[Prev(Len)][8]) % MODULA;
	}
	Sum = 0;
	for (int i = 0; i < 10; ++i)
		Sum += NumArr[Len][i];
	cout << Sum%MODULA;
	return 0;
}