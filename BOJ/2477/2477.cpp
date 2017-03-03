// =====================================================================================
// 
//       Filename:  2477.cpp
//        Created:  2017년 01월 15일 18시 59분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

struct point{
	int x, y;
	point(int x, int y):x(x), y(y){}
	point operator - (const point& rhs)const{
		return point(x-rhs.x, y-rhs.y);
	}
	int cross(const point& rhs)const{
		return x*rhs.y-y*rhs.x;
	}
};
int ccw(point a, point b){
	return a.cross(b);
}
int ccw(point p, point a, point b){
	return ccw(a-p, b-p);
}
int K;
pair<int, int> line[6];
vector<point> p;
int x, y;
int width, hight;
int dirx[5]={0, 1, -1, 0, 0 };
int diry[5]={0, 0, 0, -1, 1};
int main(){
	scanf("%d\n", &K);
	for(int i=0;i<6;i++){
		scanf("%d%d", &line[i].first, &line[i].second);
		x=x+dirx[line[i].first]*line[i].second;
		y=y+diry[line[i].first]*line[i].second;
		p.push_back(point(x, y));
		if(line[i].first==4)
			hight+=line[i].second;
		if(line[i].first==1)
			width+=line[i].second;
	}
	int ans=hight*width*K;
	for(int i=0;i<6;i++){
		if(ccw(p[i], p[(i+1)%6], p[(i+2)%6])<0)
			ans-=line[(i+1)%6].second*line[(i+2)%6].second*K;
	}
	printf("%d\n", ans);
	return 0;
}

