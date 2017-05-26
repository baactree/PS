// =====================================================================================
// 
//       Filename:  3063.cpp
//        Created:  2017년 05월 26일 19시 34분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct point{
	int x, y;
};
struct line{
	int x, ys, yf, st;
	bool operator < (const line &rhs)const{
		return x<rhs.x;
	}
};
pair<point, point> rect[2];
vector<line> l;
int len[10005];
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		memset(len, 0, sizeof(len));
		l.clear();
		for(int i=0;i<2;i++){
			scanf("%d%d%d%d", &rect[i].first.x, &rect[i].first.y, &rect[i].second.x, &rect[i].second.y);
			l.push_back({rect[i].first.x, rect[i].first.y, rect[i].second.y, 1});
			l.push_back({rect[i].second.x, rect[i].first.y, rect[i].second.y, 0});
		}
		sort(l.begin(), l.end());
		int nowx=-10005;
		int w=0;
		for(int i=0;i<l.size();i++){
			int nowh=0;
			for(int j=0;j<10005;j++)
				if(len[j])
					nowh++;
			w+=(l[i].x-nowx)*nowh;
			if(l[i].st){
				for(int j=l[i].ys;j<l[i].yf;j++)
					len[j]++;
			}
			else{
				for(int j=l[i].ys;j<l[i].yf;j++)
					len[j]--;
			}
			nowx=l[i].x;
		}
		w=(rect[0].second.x-rect[0].first.x)*(rect[0].second.y-rect[0].first.y)
			+(rect[1].second.x-rect[1].first.x)*(rect[1].second.y-rect[1].first.y)-w;
		printf("%d\n", (rect[0].second.x-rect[0].first.x)*(rect[0].second.y-rect[0].first.y)-w);

	}
	return 0;
}

