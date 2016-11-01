#include<iostream>
#include<algorithm>
using namespace std;
long Arr[2][100000];
int	 Select(int b ,int e,int Nth){
	const int pivot = b;
	int left = b, right = e;

	//Grouping
	while (left < right){
		for (; left < right&&!(Arr[1][pivot] < Arr[1][left]); ++left);
		for (; left <= right&&!(Arr[1][pivot] > Arr[1][right]); --right);
		if (left < right)
			swap(Arr[1][left++], Arr[1][right--]);
	}
	
	swap(Arr[1][right], Arr[1][b]);
	if (right == Nth)return Arr[1][right];

	if (left - 1 < Nth)
		return Select(right +1, e, Nth);
	else 
		return Select(b, right-1, Nth);	
}
int main(){
	int Num, Case;
	int begin, end, Nth;
	cin >> Num >> Case;
	int index = 0;
	for (index = 1; index <= Num; ++index)
		cin >> Arr[0][index];
	while (Case--){
		cin >> begin >> end >> Nth;
		for (int i = begin ; i <= end ; ++i)
			Arr[1][i - begin +1] = Arr[0][i];
		cout << Select(1, end-begin+1, Nth) << endl;
	}
	return 0;
}