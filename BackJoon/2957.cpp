#include<iostream>
#include<set>
using namespace std;
struct Number{
	int N;
	int Count;
	bool operator <(const Number& n)const{
		return N < n.N;
	}
	bool operator ==(const Number& n)const{
		return N == n.N;
	}
	bool operator >(const Number& n)const{
		return N > n.N;
	}
	void Set(int n, int c){ N = n; Count = c; }
};
int main(){
	set<Number> SET;
	int Num, Count = 0;
	cin >> Num;
	while (Num--){
		int Tmp;
		Number tmp;
		cin >> Tmp;
		tmp.Set(Tmp, Count++);
		SET.insert(tmp);
	}
	set<Number>::iterator it;
	for (it = SET.begin(); it != SET.end(); ++it)
		cout << it->Count << endl;
	return 0;
}