#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> score(300000,0 );
int main(){
	int Num,i,count = 0;
	int Back;
	cin >> Num;
	for (i = 0; i < Num; ++i)
		cin >> score[i];
	sort(score.begin(),score.begin()+Num);
	for (Back = 0; Back >= 0 && !(score[Num-Back-1] != score[Num - 1]); ++Back);
	for (i = 0; i < Num && !(score[i] + Num >= score[Num - 1] + Back); ++i);
	cout << Num - i << endl;
	return 0;
}