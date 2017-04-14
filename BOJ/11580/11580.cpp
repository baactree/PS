// =====================================================================================
// 
//       Filename:  11580.cpp
//        Created:  2017년 04월 14일 10시 50분 17초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > s;
int l;
string order;
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};
int p[255];
int main(){
	scanf("%d", &l);
	cin>>order;
	s.insert({0, 0});
	int x, y;
	x=y=0;
	p['E']=3;
	p['W']=2;
	p['S']=1;
	p['N']=0;
	for(int i=0;i<l;i++){
		char now=order[i];
		int nx=x+dx[p[now]];
		int ny=y+dy[p[now]];
		s.insert({nx, ny});
		x=nx;
		y=ny;
	}
	printf("%d\n", s.size());
	return 0;
}

