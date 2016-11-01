//Clear
#include <cstdio>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef  unsigned long long ull;
ull main(ull argc, char** argv) {
	vector<ull> vc(5,5);
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� prullf�� ����� ���, prullf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� prullf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	ull T;
	ull test_case;
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		vector<ull> VC;
		ull Len;
		VC.push_back(1);
		cin >> Len;
		for (ull i = 1;i<= Len; ++i){

			vector<ull>& prev = VC;
			vector<ull> tmp;
			for (size_t i = 0; i < VC.size(); ++i){
				tmp.push_back(prev[i] * 2);
				ull Ch = prev[i] - 1;
				ull Next = Ch / 3;
				if ((Ch) % 3 == 0 && (Next!= 1 && Next!=0&&Next%2==1))
					tmp.push_back((prev[i] - 1) / 3);
			}
			sort(tmp.begin(), tmp.end());
			VC.resize(0);
			if (tmp.size() > 300){
				for (ull i = 0; i < 300; ++i)
					VC.push_back(tmp[i]);
				VC.push_back(tmp.back());
			}
			else
				VC = tmp;
		}
		sort(VC.begin(), VC.end());
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ prullf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		prullf("Case #%d\n", test_case);	
		cout << VC.front() << " " << (ull)pow(2, Len) << endl;
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}