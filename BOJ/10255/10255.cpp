// =====================================================================================
// 
//       Filename:  10255.cpp
//        Created:  2017년 05월 26일 15시 20분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
class point{
public:
	int x, y;
	point(){}
	point(int x, int y):x(x), y(y){}
	int cross(const point &rhs)const{
		return x*rhs.y-y*rhs.x;
	}
	point operator - (const point &rhs)const{
		return {x-rhs.x, y-rhs.y};
	}
	bool operator < (const point &rhs)const{
		if(x==rhs.x)
			return y<rhs.y;
		return x<rhs.x;
	}
	point operator * (int rhs)const{
		return {x*rhs, y*rhs};
	}
	point operator + (const point &rhs)const{
		return {x+rhs.x, y+rhs.y};
	}
	bool operator == (const point &rhs)const{
		return x==rhs.x&&y==rhs.y;
	}
};
int ccw(point a, point b){
	int ret=a.cross(b);
	if(ret>0)
		return 1;
	if(ret<0)
		return -1;
	return 0;
}
int ccw(point p, point a, point b){
	return ccw(a-p, b-p);
}
bool isparallel(point a, point b, point c, point d){
	return (b-a).cross(d-c)==0;
}
int go(point a, point b, point c, point d){
	if(b<a)
		swap(a, b);
	if(d<c)
		swap(c, d);
	if(ccw(a, b, c)!=0||d<a||b<c)
		return 0;
	if(a<c&&b==c)
		return 1;
	if(c<a&&d==a)
		return 1;
	return 2;
}
int go2(point a, point b, point c, point d){
	int ab=ccw(a, b, c)*ccw(a, b, d);
	int cd=ccw(c, d, a)*ccw(c, d, b);
	if(ab==0&&cd==0){
		return 1;
	}
	if(ab==0&&cd<0)
		return 1;
	if(ab<0&&cd<=0)
		return 2;
	return 0;
}
vector<pair<point, point> > rect;
pair<point, point> line;
int solve(){
	int cnt=0;
	int rcnt=0;
	for(int i=0;i<4;i++){
		if(isparallel(line.first, line.second, rect[i].first, rect[i].second)){
			int ret=go(line.first, line.second, rect[i].first, rect[i].second);
			if(ret==1)
				rcnt++;
			if(ret==2)
				return 4;
		}
		else{
			int ret=go2(line.first, line.second, rect[i].first, rect[i].second);
			if(ret==1)
				rcnt++;
			if(ret==2)
				cnt++;
		}
	}
	return cnt+rcnt/2;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		rect.clear();
		int xmin, ymin, xmax, ymax;
		scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);
		rect.push_back({{xmin, ymin}, {xmin, ymax}});
		rect.push_back({{xmin, ymax}, {xmax, ymax}});
		rect.push_back({{xmax, ymax}, {xmax, ymin}});
		rect.push_back({{xmax, ymin}, {xmin, ymin}});
		scanf("%d%d%d%d", &line.first.x, &line.first.y, &line.second.x, &line.second.y);
		printf("%d\n", solve());
	}
	return 0;
}

