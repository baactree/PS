#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
struct point{
	typedef long long T;
	T x, y;
	point(){}
	point(T x, T y) :x(x), y(y) {}
	bool operator == (const point& rhs)const {
		return x == rhs.x&&y == rhs.y;
	}
	bool operator < (const point& rhs)const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	point operator + (const point&rhs)const {
		return point(x + rhs.x, y + rhs.y);
	}
	point operator - (const point&rhs)const {
		return point(x - rhs.x, y - rhs.y);
	}
	point operator * (T rhs)const {
		return point(x*rhs, y*rhs);
	}
	// 벡터의 길이
	double norm() const {
		return hypot(x,y);
	}
	// 단위 벡터
	point normalize() const {
		return point(x / norm(), y / norm());
	}
	// x축의 양의 방 향으로부터 이 벡터까지 반시계 방향으로 잰 각도
	double polar() const {
		return fmod(atan2(y, x)+2*PI, 2*PI);
	}
	//내적
	T dot(const point&rhs)const {
		return x*rhs.x + y*rhs.y;
	}
	//외적
	T cross(const point&rhs)const {
		return x*rhs.y - rhs.x*y;
	}
};
typedef long long ll;
//원점 기준 b가 a의 반시계 > 0, 시계 < 0, 평행 = 0
int ccw(point a, point b){
	ll ret=a.cross(b);
	if(ret<0)
		return -1;
	if(ret>0)
		return 1;
	return 0;
}

//p 기준 b가 a의 반시계 > 0, 시계 < 0, 평행 = 0
int ccw(point p, point a, point b){
	return ccw(a-p, b-p);
}

vector<point> graham(vector<point>& input){
	int n = input.size();
	vector<point> hull;
	vector<point> up(n), down(n);
	int iup, idown;
	iup = idown = -1;
	sort(input.begin(),  input.end());
	for(int i=0;i<n;i++){
		while(iup>0&&ccw(up[iup-1], up[iup], input[i])>=0)
			iup--;
		up[++iup]=input[i];
		while(idown>0&&ccw(down[idown-1], down[idown], input[i])<=0)
			idown--;
		down[++idown]=input[i];
	}
	for(int i=0;i<=iup;i++)
		hull.push_back(up[i]);
	for(int i=idown-1;i>0;i--)
		hull.push_back(down[i]);
	return hull;
}
int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		int n;
		vector<point> arr;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			arr.push_back({x,y});
		}
		vector<point> hull=graham(arr);
		point st(-0x3f3f3f3f,-0x3f3f3f3f);
		int idx=-1;
		for(int i=0;i<hull.size();i++){
			if(hull[i].y>st.y){
				st=hull[i];
				idx=i;
			}
			else if(hull[i].y==st.y&&hull[i].x<st.x){
				st=hull[i];
				idx=i;
			}
		}
		cout<<hull.size()<<endl;
		for(int i=0;i<hull.size();i++){
			int now=(i+idx)%hull.size();
			printf("%d %d\n",hull[now].x,hull[now].y);
		}
	}
	return 0;
}