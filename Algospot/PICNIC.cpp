#include<iostream>
using namespace std;
int pn, cn;
bool couple[10][10];
bool check[10]; 
int Find(){
	for (int i = 0; i < pn; ++i)
		;
}
int main()
{
	int Case;
	cin >> Case;
	while (Case--){
		cin >> pn >> cn;
		for (int r = 0; r < pn; ++r)
			for (int c = 0; c < pn; ++c)
				couple[r][c] = false;
		for (int i = 0; i < cn; ++i){
			int b, e;
			cin >> b >> e;
			couple[b][e] = couple[e][b] = true;
		}
	}
	return 0;
}