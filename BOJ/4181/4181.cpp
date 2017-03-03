// =====================================================================================
// 
//       Filename:  4181.cpp
//        Created:  2017년 01월 15일 03시 26분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

const double PI = 2.0 * acos(0.0);

struct point{
	double x, y;
	explicit point(double x = 0, double y = 0) :x(x), y(y) {}
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
	point operator * (int rhs)const {
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
	double dot(const point&rhs)const {
		return x*rhs.x + y*rhs.y;
	}
	//외적
	double cross(const point&rhs)const {
		return x*rhs.y - rhs.x*y;
	}
};
double ccw(point a, point b){
	return a.cross(b);
}
double ccw(point p, point a, point b){
	return ccw(a-p, b-p);
}
// O(nlgn) convex hull
vector<point> graham(vector<point>& input){
	int n = input.size();
	vector<point> hull;
	vector<point> up(n), down(n);
	int idx, iup, idown;
	iup = idown = -1;
	sort(input.begin(),  input.end());
	for(int i=0;i<n;i++){
		while(iup>0&&ccw(up[iup-1], up[iup], input[i])>0)
			iup--;
		up[++iup]=input[i];
		while(idown>0&&ccw(down[idown-1], down[idown], input[i])<0)
			idown--;
		down[++idown]=input[i];
	}
	for(idx=0;idx<=idown;idx++)
		hull.push_back(down[idx]);
	for(int i=iup-1;i>0;i--)
		hull.push_back(up[i]);
	return hull;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<point> input(n);
	for(int i=0;i<n;i++){
		char temp[2];
		scanf("%lf%lf%s", &input[i].x, &input[i].y, temp);
	}
	vector<point> hull = graham(input);
	printf("%d\n", hull.size());
	for(auto i:hull){
		printf("%d %d\n", (int)i.x, (int)i.y);
	}
	return 0;
}
