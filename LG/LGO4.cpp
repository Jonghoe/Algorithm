#include<stdio.h>
#include<vector>
using namespace std;
struct P_XYY{
	int x, y1, y2;
	P_XYY(){ x = -1, y1 = -1, y2 = -1; }
};
struct P_XY{
	int x, y;
	P_XY(){ x = -1; y = -1; }
	P_XY(int _x, int _y) :x(_x), y(_y){}
};
double CalDist(P_XY& A, P_XY&B){
	return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}
bool IsOK(P_XY&A, P_XY&B, P_XYY& C){
	double x1=A.x, x2=B.x, y1=A.y, y2=B.y;
	double M = (y2 - y1) / (x2 - x1);
	
	return C.y1 <= M*C.x&&M*C.x <= C.y2;
}
int Y(P_XY& A, P_XY&B, P_XY& C){
	double x1 = A.x, x2 = B.x, y1 = A.y, y2 = B.y;
	double M = (y2 - y1) / (x2 - x1);
	return M*C.x;
}
double Cal(vector<P_XYY>& vc){
	double Ret_V=0;
	vector<P_XYY> SRC;
	for (int i = 0; i < vc.size() - 2; ++i){
		if (vc[i].y2 < vc[i + 1].y1){
			if (vc[i+1].y2)
		}
	}
}
int main(){
	FILE* IF;
	FILE* OF;
	int Case;
	vector<P_XYY> data;
	vector<P_XY> DP;
	IF = fopen("input.txt", "r");
	OF = fopen("output.txt", "w");
	fscanf(IF, "%d", &Case);
	while (Case--){
		P_XYY tmp;
		int Num,i;
		DP.push_back(P_XY());
		fscanf(IF, "%d", &Num);
		for (i = 0; i < Num; ++i){
			fscanf(IF, "%d%d%d", &tmp.x, &tmp.y1, &tmp.y2);
			data.push_back(tmp);
		}
		printf("%f\n", Cal(data));
		data.resize(0);
		DP.resize(0);
	}
	fclose(IF);
}