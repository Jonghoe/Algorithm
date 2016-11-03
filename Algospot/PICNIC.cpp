#include<iostream>
using namespace std;
/*
URL: https://algospot.com/judge/problem/read/PICNIC
ÇØ°á
*/
int pn, cn;
bool couple[10][10];
bool alone[10]; 
int Count;
void Search(int b){
	if (b >= pn){
		++Count;
		return;
	}
	if (alone[b]){
		alone[b] = false;
		for (int i = 0; i < pn; ++i)
			if (couple[b][i] && alone[i]){
				alone[i] = false;
				Search(b+1);
				alone[i] = true;
			}
		alone[b] = true;
	}
	else
		Search(b + 1);
}

int main()
{
	int Case;
	cin >> Case;
	while (Case--){
		Count = 0;
		cin >> pn >> cn;
		for (int i = 0; i < 10; ++i)
			alone[i] = true;
		for (int r = 0; r < pn; ++r)
			for (int c = 0; c < pn; ++c)
				couple[r][c] = false;
		for (int i = 0; i < cn; ++i){
			int b, e;
			cin >> b >> e;
			couple[b][e] = couple[e][b] = true;
		}
		Search(0);
		cout << Count << endl;
	}
	return 0;
}
