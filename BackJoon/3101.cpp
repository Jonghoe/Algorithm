#include<iostream>
#include<fstream>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;

struct Number{
	int n;
	int Count;
	
	bool operator ==(const Number& N)const{
		return N.n == n;
	}
	bool operator <(const Number& N)const{
		return Count < N.Count;
	}
	bool operator >(const Number& N)const{
		return Count > N.Count;
	}
};

int main(){
	int Num,Max;
	Number N;
	ifstream IF("input.txt");
	vector<Number> vcN;
	IF>> Num >> Max;
	for (int i = 0; i < Num; ++i){
		IF >> N.n;
		N.Count = 1;
		auto it = find(vcN.begin(), vcN.end(), N);
		if (it == vcN.end())			//�� ã�� ��� 
			vcN.push_back(N);
		else							//count ����
			++it->Count;
	}

	sort(vcN.begin(), vcN.end(),greater<Number>());//count�� ū������ ����

	for (size_t i = 0; i < vcN.size(); ++i)
	for (int j = 0; j < vcN[i].Count; ++j)
		cout << vcN[i].n << ' ';
		
	return 0;
}