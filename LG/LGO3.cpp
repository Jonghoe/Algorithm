#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
struct Point{
	LL x, y;
	Point() :x(), y(){}
	Point(LL X, LL Y) :x(X), y(Y){}
	bool operator==(const Point& p)const{
		return  p.y == y;
	}
};
struct Rect{
	Point LT, RB;
	Rect(Point& lt, Point& rb):LT(lt), RB(rb){}
	virtual bool IsContain(Point& p) = 0;

};
struct OutRect :public Rect{
	OutRect(Point&lt ,Point& rb):Rect(lt,rb){}
	bool IsContain(Point& p){
		return (LT.x <= p.x&&p.x <= RB.x&&
			RB.y <= p.y&&p.y <= LT.y);
	}
};
struct InRect :public Rect{

	InRect(Point&lt, Point& rb) :Rect(lt, rb){}
	bool IsContain(Point& p){
		return (LT.x < p.x&&p.x < RB.x&&
			RB.y < p.y&&p.y < LT.y);
	}
};
bool Xorder(Point& A, Point& B){
	return A.x < B.x;
}
bool Yorder(Point& A, Point& B){
	return A.y < B.y;
}
struct Less{
	Point& dst;
	Less(Point& p) :dst(p){};
	bool operator ==(Point& P){
		return P.y <= dst.y;
	}
};
//bool Check(vector<Point&> vc, int W, int K){
//	LL L, R, B, U;
//	int Count = 0;
//	sort(vc.begin(), vc.end(), Xorder);
//	L = vc[0].x;
//	R = vc[vc.size() - 1].x;
//	sort(vc.begin(), vc.end(), Yorder);
//	B = vc[0].y;
//	U = vc[vc.size() - 1].y;
//	Rect& Out = OutRect(Point(L, U), Point(R, B));
//	Rect& In = InRect(Point(L + W, U - W), Point(R - W, B + W));
//
//	for (size_t i = 0; i < vc.size(); ++i){
//		if (!(Out.IsContain(vc[i]) && !In.IsContain(vc[i])))
//			Count++;
//		if (Count > K)
//			return false;
//	}
//	return true;
//	
//}
bool Moidfy(vector<Point>&vc,Rect& In,Rect& Out, int W, int K, vector<Point>& miss){
	vector<LL> LEN;
	vector<Point> MISS;
	int front=0, back=vc.size()-1;
	LL Dist = miss[miss.size() - 1].y - miss[0].y;
	LL Length=0;
	for (int i = 0; i < K; ++i){
		MISS = miss;
		//if (vc[front + 1].y - vc[front].y >vc[back].y - vc[back - 1].y){
		//	Length = vc[front + 1].y - vc[front].y;
		//	In.RB.y += Length;
		//	Out.RB.y += Length;
		//}
		//else{
		//	LEN.push_back(vc[back].y - vc[back - 1].y);
		//	In.LT.y -= LEN[LEN.size() - 1];
		//	Out.LT.y -= LEN[LEN.size() - 1];
		//}

		if (MISS.size() <= K - i)
			return true;
	}
	for (int i = 0; i < miss.size(); ++i)
		if (!(Out.IsContain(miss[i]) && !In.IsContain(miss[i])))
			return false;
	return true;
}

bool Cal(vector<Point>& vc,int W,int K){
	LL L, R,U,B;
	int Count = 0;
	vector<Point> Miss;
	sort(vc.begin(), vc.end(), Xorder);
	L = vc[0].x;
	R = vc[vc.size() - 1].x;
	sort(vc.begin(), vc.end(), Yorder);
	B = vc[0].y;
	U = vc[vc.size()-1].y;
	Rect& Out = OutRect(Point(L, U), Point(R, B));
	Rect& In = InRect(Point(L + W, U - W), Point(R - W, B + W));
	
	for (size_t i = 0; i < vc.size(); ++i){
		if (!(Out.IsContain(vc[i]) && !In.IsContain(vc[i])))
			Miss.push_back(vc[i]);
	}	
	if (Miss.size() > K)
		return Moidfy(vc,In,Out,W,K,Miss);
	return true;
}
int main(){
	FILE* IF;
	FILE* OF;
	int Case;
	IF = fopen("input.txt", "r");
	OF = fopen("output.txt", "r");
	fscanf(IF, "%d", &Case);
	while (Case--){
		vector<Point> vc;
		int NS,NT,W;
		Point tmp;
		fscanf(IF, "%d", &NS);
		fscanf(IF, "%d", &NT);
		fscanf(IF, "%d", &W);
		for (int i = 0; i < NS; ++i){
			fscanf(IF, "%lld%lld", &tmp.x, &tmp.y);
			vc.push_back(tmp);
		}
		if (Cal(vc,W,NT))
			fprintf(OF,"YES\n");
		else
			fprintf(OF,"NO\n");
	}
	
}