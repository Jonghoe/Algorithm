#include<iostream>
#include<vector>
using namespace std;
template <typename IT>
typename IT::value_type ADD(IT b, IT e){
	typename IT::value_type Sum = 0;
	for (; b != e; ++b)
		Sum += *b;
	return Sum;
}
int main(){
	int Sum = 0,tmp;
	char op;
	vector<int> Num;
	vector<int>change;
	while (!cin.fail() ){
		cin >> tmp;
		Num.push_back(tmp);
		cin >> op;
		if (op == '-')
			change.push_back(Num.size());
	}
	
	if (change.size() == 0)
		Sum = ADD(Num.begin(), Num.end());// ù��° �׷�
	else{
		
		Sum = ADD(Num.begin(), Num.begin() + change[0]);//ù��° �׷�
		for (size_t i = 0; i < change.size();++i)		//������ �׷�
			if (i == change.size() - 1)
				Sum -= ADD(Num.begin() + change[i], Num.end());
			else
				Sum -= ADD(Num.begin() + change[i], Num.begin() + change[i + 1]);
		
	}
	cout << Sum << endl;
	return 0;
}