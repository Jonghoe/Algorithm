//Clear
#include <cstdio>
#include<algorithm>
#include <iostream>
#include<vector>

using namespace std;
struct Node{
	vector<bool> Edge;
	Node(ull Num, bool INlist<char>::iterator) :Edge(Num, INlist<char>::iterator){ Degree = 0; }
	ull Degree;
	const bool& operator [](ull i)const{
		return Edge[i];
	}
	vector<bool>::reference operator [](ull i){
		vector<bool>::reference BL = Edge[i];
		return Edge[i];
	}
};
typedef vector<bool>::size_type sz_type;
void removeNode(vector<Node>& gr, ull ID){
	for (sz_type e = 1; e < gr[ID].Edge.size(); ++e)
		if (gr[ID][e]){
			gr[ID][e] = gr[e][ID]=false;
			--gr[e].Degree;
		}
	gr[ID].Degree = -1;
}
bool removeHigh(vector<Node>& gr, ull K, ull L,ull& N){
	for (sz_type s = 1; s < gr.size(); ++s){
		if (gr[s].Degree >=0 && N - gr[s].Degree<= L){
			removeNode(gr, s);
			return true;
		}
	}
	return false;
}
bool removeLow(vector<Node>& gr, ull K,ull& N){
	for (sz_type s = 1; s < gr.size(); ++s){
		
		if (gr[s].Degree >=0 && gr[s].Degree< K){
			removeNode(gr, s);
			--N;
			return true;
		}
	}
	return false;
}
ull main(ull argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,%
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
		ull K, L, N, M,sum,NN;
		vector<Node > Graph;
		scanf("%d%d", &K, &L);
		scanf("%d%d", &N, &M);
		Graph.assign(N + 1, Node(N + 1, false));
		for (ull i = 0; i < M; ++i){
			ull s, e;
			scanf("%d%d", &s, &e);
			Graph[s][e] = Graph[e][s] = true;
			++Graph[s].Degree;
			++Graph[e].Degree;
		}
		sum = 0;
		NN = N;
		while (1){
			while (removeLow(Graph, K,N));
			if (!removeHigh(Graph, K, L, N))
				break;
		}
		for (ull i = 1; i <= NN; ++i)
			if (Graph[i].Degree < 0)sum += i;
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ prullf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		prullf("Case #%d\n", test_case);
		prullf("%d\n", sum);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}