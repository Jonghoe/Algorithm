#include<iostream>

using namespace std;
int calc(int N, int M){
	if (N / 2 >= M)
		return M;
	else
		return N / 2;
}
int main(){
	int N, M, K;
	cin >> N >> M >> K;
	int Max = calc(N - K, M);
	for (int i = 1; i <= K; ++i){
		if (Max < calc(N - (K - i), M - i))
			Max = calc(N - (K - i), M - i);
	}
	cout << Max << endl;
	return 0;
}