#include<iostream>
#include<string>
using namespace std;
char BOARD[5][5];
string word;

bool FIND(int r, int c,string word){			
	if (r < 0 && r >= 5)
		return false;
	if (c < 0 && c >= 5)
		return false;
	if (BOARD[r][c] != word.front())
		return false;
	else{
		if (word.length() == 1)
			return true;
		for (int rr = -1; rr <= 1; ++rr)
			for (int cc = -1; cc <= 1; ++cc)
				if (r + rr != r || c + cc != c){
					
					if(FIND(r + rr, c + cc, word.substr(1)))
						return true;
				}
		return false;
	}
}
int main(){
	int testCase;
	cin >> testCase;
	while (testCase--){
		int Num;
		for (int r = 0; r < 5; ++r)
		for (int c = 0; c < 5; ++c)
			cin >> BOARD[r][c];
		cin >> Num;
		while (Num--){
			char DP[5][5] = { 0 };
			for (int r = 0; r < 5; ++r)
				for (int c = 0; c < 5; ++c)
					DP[r][c] = BOARD[r][c];
			cin >> word;
			cout << word << " ";
			int r;
			for (r = 0; r < 5; ++r)
			for (int c = 0; c < 5; ++c)
				if (FIND(r,c,word)){
						cout << "YES" << endl;
						r = 6;
				}
			if (r < 6)
				cout << "NO" << endl;
		}
	}
}