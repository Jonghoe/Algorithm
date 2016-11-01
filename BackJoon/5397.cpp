#include<iostream>
#include<list>
#include<iterator>
#include<string>
using namespace std;
void left(list<char>::iterator& l, list<char>::iterator& it){
	if (it == l)
		return;
	else
		--it;
}
void right(list<char>::iterator& l, list<char>::iterator& it){
	if (it == l)
		return;
	else
		++it;
}int main(){
	int Case;
	cin >> Case;
	while (Case--){
		list<char> pwd;
		list<char>::iterator it = pwd.begin();
		string word;
		cin >> word;
		for (int i = 0; i < word.size(); ++i){
			if (word[i] == '<'){
				if(pwd.begin() != it)
				--it;
			}
			else if (word[i] == '>'){
				if (pwd.end() != it)
					++it;
			}
			else if (word[i] == '-'){
				if (pwd.size() != 0){
					if (it == pwd.end())
						pwd.pop_back();
					else if (it != pwd.begin()){
						it = pwd.erase(--it);
					}
				}
			}
			else
				pwd.insert(it,word[i]);
		}
		for (auto it = pwd.begin(); it != pwd.end(); ++it)
			cout << *it;
 		cout << endl;
	}
	return 0;
}