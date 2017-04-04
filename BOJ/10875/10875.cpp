// =====================================================================================
// 
//       Filename:  10875.cpp
//        Created:  2017년 04월 03일 22시 13분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Line{
	int x1, y1, x2, y2;
	int dir;
	Line(){}
	Line(int x1, int y1, int x2, int y2):x1(x1), y1(y1), x2(x2), y2(y2){
		if(x1==x2)
			dir=0;
		else
			dir=1;
		set_point();
	}
	void set_point(){
		if(x1>x2)
			swap(x1, x2);
		if(y1>y2)
			swap(y1, y2);
	}
};
vector<Line> line;
int l, n;
const int inf=0x3f3f3f3f;
pair<int, int> spin[1001];
int dx[4]={0, -1, 0, 1};
int dy[4]={1, 0, -1, 0};
int main(){
	scanf("%d%d", &l, &n);
	for(int i=0;i<n;i++){
		char input[2];
		scanf("%d%s", &spin[i].first, input);
		if(input[0]=='L')
			spin[i].second=1;
		else
			spin[i].second=-1;
	}
	spin[n]={inf, -1};
	//초기 테두리
	line.push_back(Line(-l-1, -l-1, l+1, -l-1));
	line.push_back(Line(-l-1, -l-1, -l-1, l+1));
	line.push_back(Line(-l-1, l+1, l+1, l+1));
	line.push_back(Line(l+1, -l-1, l+1, l+1));
	int x, y, dir;
	x=y=0;
	dir=3;
	//상좌하우
	long long ans=0;
	for(int i=0;i<=n;i++){
		int t=inf;
		for(int j=0;j<line.size();j++){
			if(line[j].dir==0){
				if(dir==0){
					if(x==line[j].x1&&y<line[j].y1){
						t=min(t, line[j].y1-y);
					}
				}
				else if(dir==1){
					if(line[j].y1<=y&&y<=line[j].y2&&line[j].x1<x)
						t=min(t, x-line[j].x1);
				}
				else if(dir==2){
					if(x==line[j].x1&&line[j].y2<y){
						t=min(t, y-line[j].y2);
					}
				}
				else{
					if(line[j].y1<=y&&y<=line[j].y2&&x<line[j].x1)
						t=min(t, line[j].x1-x);
				}
			}
			else{
				if(dir==0){
					if(line[j].x1<=x&&x<=line[j].x2&&y<line[j].y1){
						t=min(t, line[j].y1-y);
					}
				}
				else if(dir==1){
					if(line[j].y1==y&&line[j].x2<x)
						t=min(t, x-line[j].x2);
				}
				else if(dir==2){
					if(line[j].x1<=x&&x<=line[j].x2&&line[j].y1<y)
						t=min(t, y-line[j].y1);
				}
				else{
					if(line[j].y1==y&&x<line[j].x1)
						t=min(t, line[j].x1-x);
				}
			}
		}
		if(t<=spin[i].first){
			printf("%lld\n", ans+t);
			return 0;
		}
		ans+=spin[i].first;
		int nx=x+dx[dir]*spin[i].first;
		int ny=y+dy[dir]*spin[i].first;
		dir=(dir+spin[i].second+4)%4;
		line.push_back(Line(x, y, nx, ny));
		x=nx;
		y=ny;
	}
	return 0;
}

