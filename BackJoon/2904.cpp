#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef size_t ID;
struct Edge{
	ID S, E;
	int V;
	bool Used;
	Edge() :S(0), E(0), V(0){ Used = false; }
	Edge(ID s, ID e, int v) :S(s), E(e), V(v){ Used = false; }
	Edge(const Edge& e) :S(e.S), E(e.E), V(e.V),Used(e.Used){ }
	bool operator <(const Edge& e){ return V < e.V; }
};
struct Node{
	vector<Edge*> EVc;
	bool Visited;
	Node() :EVc(), Visited(false){}
};
void ClearUsed(vector<Edge>::iterator b, vector<Edge>::iterator e){
	for (; b != e; ++b)
		(*b).Used = false;
}
bool Circulation(const vector<Node>& NVc, ID Start,ID End){
	bool Ret_V = false;
	for (size_t i = 0; i < NVc[Start].EVc.size(); ++i){
		if (NVc[Start].EVc[i]->S == Start){
			Edge* Ed = NVc[Start].EVc[i];
			if (!Ed->Used &&Ed->E == End)
				return true;
			else if (!Ed->Used){
				Ed->Used = true;
				Ret_V |= Circulation(NVc, Ed->E, End);
			}
		}
		else{
			Edge* Ed = NVc[Start].EVc[i];
			if (!Ed->Used &&Ed->S == End)
				return true;
			else if(!Ed->Used){
				Ed->Used = true;
				Ret_V |= Circulation(NVc, Ed->S, End);
			}
		}
		if (Ret_V == true)
			return true;
	}
	return Ret_V;
}
int main(){
	size_t NodeN,EdgeN;
	cin >> NodeN >> EdgeN;
	size_t Order = 0;
	int Value=0;
	
	vector<Edge> EVc(EdgeN);
	vector<Node> NVc(NodeN+1);

	size_t S, E;
	int V;
	for (size_t i = 0; i < EdgeN; ++i){
		cin >> S >> E >> V;
		EVc[i] = (Edge(S, E, V));
	}
	sort(EVc.begin(), EVc.end());
	for (size_t i = 0; i < EVc.size() && !( Order== NodeN-1);++i)
		if (Order != 0)
			if (NVc[EVc[i].S].Visited &&NVc[EVc[i].E].Visited){
				NVc[EVc[i].S].EVc.push_back(&EVc[i]);
				NVc[EVc[i].E].EVc.push_back(&EVc[i]);
				ID Start = EVc[i].S;
				ClearUsed(EVc.begin(), EVc.begin() + i);
				if (Circulation(NVc, Start, Start)){
					NVc[EVc[i].S].EVc.pop_back();
					NVc[EVc[i].E].EVc.pop_back();
				}
				else{
					Order += 1;
					Value += EVc[i].V;
				}
			}
			else{
				NVc[EVc[i].S].Visited = true;
				NVc[EVc[i].E].Visited = true;
				NVc[EVc[i].S].EVc.push_back(&EVc[i]);
				NVc[EVc[i].E].EVc.push_back(&EVc[i]);
				Order += 1;
				Value += EVc[i].V;
			}
		else{
			NVc[EVc[i].S].Visited = true;
			NVc[EVc[i].E].Visited = true;
			NVc[EVc[i].S].EVc.push_back(&EVc[i]);
			NVc[EVc[i].E].EVc.push_back(&EVc[i]);
			Order += 1;
			Value += EVc[i].V;
		}
		cout << Value;
}