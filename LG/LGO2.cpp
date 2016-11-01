#include<stdio.h>

int Arr[10001][10001];
int Arr2[10001][10001];
bool Check[10001][10001];
int V, N, Count;

void MBP(int src, int dst,int Ret){
	if (Arr2[dst][dst] != 0 && Ret <Arr2[dst][dst] )
		return;
	
	if (src == dst){
		if (Arr2[src][dst] == 0 || Arr2[src][dst]<Ret)
			Arr2[src][dst] = Ret;
		return;
	}
	if (Arr[src][dst] != 0){
		Check[src][dst] = true;
		Check[dst][src] = true;
		if (Ret >= Arr[src][dst])
			MBP(dst, dst, Arr[src][dst]);
		else
			MBP(dst, dst, Ret);
		Check[src][dst] = false;
		Check[dst][src] = false;
	}
	for (int c = 1; c <= V; ++c){
		if (c!=dst&&Arr[src][c] != 0 && !Check[src][c]){
			Check[src][c] = true;
			Check[c][src] = true;
			if ( Ret >= Arr[src][c])
				MBP(c, dst, Arr[src][c]);
			else
				MBP(c, dst, Ret);
			Check[src][c] = false;
			Check[c][src] = false;
		}
	}
}

int main(){
	FILE* IF, *OF;
	int Case;
	IF = fopen("input.txt", "r");
	OF = fopen("output.txt", "w");
	fscanf(IF, "%d", &Case);
	while (Case--){
		fscanf(IF, "%d%d", &V, &N);
		for (int r = 0; r < V; ++r)
			for (int c = 0; c < V; ++c){
			Arr[r][c] = 0;
			Check[r][c] = false;
			}
		for (int i = 0; i < N; ++i){ 
			int src, dst, Value;
			fscanf(IF, "%d%d%d", &src, &dst, &Value);
			Arr[src][dst] = Value;
			Arr[dst][src] = Value;
		}
		fscanf(IF, "%d", &Count);
		int Sum = 0;
		for (int i = 0; i < Count; ++i){
			int dst, src;
			fscanf(IF, "%d%d", &dst, &src);
			MBP(src, dst,10000000);
			Sum += Arr2[dst][dst];
		}
	}
	return 0;
}

//void FindRoot(int dst, int src, int Min,int Count){
//	if (Count == 0)
//		return ;
//	if (dst == src){
//		if (Arr2[dst][src] > Min)
//			Arr2[dst][src] = Min;
//	}
//	for (int i = 0; i < V;++i)
//		if (i != src){
//			int Tmp = Min <= Arr[dst][src] ? Min : Arr[dst][src];
//			FindRoot(dst, i, Tmp, Count - 1);
//		}
//}
//void CalCulate(){
//	for (int r = 0; r < V; ++r)
//		for (int c = 0; c < V; ++c){
//			FindRoot(r, c, 10000000, V);
//		}
//}
