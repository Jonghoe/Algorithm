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
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,%
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 prullf를 사용할 경우, prullf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 prullf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	ull T;
	ull test_case;
	
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 prullf 사용을 권장하며, cout을 사용하셔도 됩니다.
		prullf("Case #%d\n", test_case);
		prullf("%d\n", sum);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}