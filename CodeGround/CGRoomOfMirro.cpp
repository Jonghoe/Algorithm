// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
#include<string>
using namespace std;
typedef unsigned long long ull;
ull cal(int r, int c, int Len){
	int N, Value;
	if (r + c <= Len + 1){
		N = r + c - 2;
		Value = (N*(N + 1)) / 2 + 1;
		if ((r + c) % 2 == 0)
			Value += c - 1;
		else
			Value += r - 1;
		return Value;
	}
	else{
		int a1 = Len;
		N = r + c - (Len + 1);
		Value = (Len - 1)*Len / 2 + 1 + (2 * a1 - (N - 1))*N / 2;
		if ((r + c) % 2 == 0)
			Value += Len - r;
		else
			Value += Len - c;
		return Value;
	}
}
int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
	int a[3];
	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		int r = 1, c = 1;
		int Len, Num,Tresh;
		char Dict;
		ull sum = 1;
		cin >> Len ;
		cin >> Num;
		for (int i = 0; i < Num; ++i){
			cin >> Dict;
			if (Dict == 'D')
				r += 1;
			else if (Dict== 'U')
				r -= 1;
			else if (Dict== 'R')
				c += 1;
			else if (Dict== 'L')
				c -= 1;
			sum += (ull)cal(r,c,Len);
		}
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		printf("%lld\n", sum);
	}
	qsort(a,(&a[0]+3),sizeof(int));
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}