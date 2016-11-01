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
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	ull TC;
	ull test_case;

	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
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
		// �� �κп��� ������ ����Ͻʽÿ�.
		prullf("Case #%d\n%d\n", test_case,Answer);	// cout ��� ����
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}