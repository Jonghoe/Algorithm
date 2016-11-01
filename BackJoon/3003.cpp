#include<iostream>
using namespace std;
ull max(ull a, ull b, ull c){
	if (a >= b && a >= c)
		return a;
	if (a >= b && c > a)
		return c;
	if (b > a && b >= c)
		return b;
	if (b > a&&c > b)
		return c;
}
ull main(){
	ull Arr[100002];
	ull DP[100002] = { 0 };
	ull Num,Count=1;
	cin >> Num;
	while (Num--){
		cin >> Arr[Count];
		DP[Count++] = 0;
	}
	DP[0] = 0;
	DP[1] = Arr[1];
	DP[2] = Arr[1]+Arr[2];
	for (ull i = 3; i <= Count; ++i)
		DP[i] = max(DP[i - 1], Arr[i] +DP[i - 2], Arr[i] + Arr[i - 1] + DP[i - 3]);
	cout << DP[Count] << endl;
	return 0;
}	