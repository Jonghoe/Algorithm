//Clear
#include <cstdio>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

ull Calculate(vector<ull>& Ar,ull Max){
	ull Count = 0,Next,j;
	for (ull i = 0; i < Ar.size();){
		if (Ar[i] == Ar.back())
			return Count;
		if (Ar[i] + Max < Ar[i + 1])
			return -1;
		if (Max + i >= Ar.size())
			Next = Ar.size() - i - 1;
		else
			Next = Max;
		for ( j = Next + i; j > 0 && !(Ar[j] <= Ar[i] + Max); --j);
			i = j;
		++Count;
	}
}
ull main(ull argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	ull TC;
	ull test_case;

	scanf("%d", &TC);	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
		ull Answer,Num,Max;
		vector<ull> VC(0,1);
		cin >> Num;
		VC.push_back(0);
		for (ull i = 1; i <= Num; ++i){
			ull Idx;
			cin >> Idx;
			VC.push_back(Idx);
		}
		cin >> Max;
		Answer = Calculate(VC, Max);
		// 이 부분에서 정답을 출력하십시오.
		prullf("Case #%d\n%d\n", test_case,Answer);	// cout 사용 가능
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}