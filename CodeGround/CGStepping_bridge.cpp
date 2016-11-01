//Clear
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
#define MOD 1000000009
class DP{
public:
	bool Mine;
	ull Count;
	static int Max;
	vector<ull> PrevJump;
	DP() :PrevJump(DP::Max, 0){ Mine = false; Count = 0; }
	ull Sum(int No){
		return Count - PrevJump[No];
	}
};
int DP::Max;

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		int SN,  MN;
		vector<DP> dp;
		scanf("%d%d%d", &SN, &DP::Max, &MN);
		DP::Max += 1;
		dp.resize(SN+1);
		//���� ��ġ
		for (int i = 0; i < MN; ++i){
			int Loc;
			scanf("%d", &Loc);
			dp[Loc].Mine = true;
		}

		for (int i = 1; i <= SN; ++i)
			if (!dp[i].Mine)
				for (int j = 1; j<=i&&j < DP::Max; ++j)
					if (i - j >0&&!dp[i-j].Mine){
						dp[i].PrevJump[j] = dp[i - j].Sum(j)%MOD;
						dp[i].Count += dp[i].PrevJump[j]%MOD;
					}
					else if (i == j&&!dp[i-j].Mine ){
						dp[i].PrevJump[j] = 1;
						dp[i].Count += dp[i].PrevJump[j]%MOD;
					}
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%lld\n", dp[SN].Sum(0) % MOD);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}