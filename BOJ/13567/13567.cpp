// =====================================================================================
// 
//       Filename:  13567.cpp
//        Created:  2017년 05월 08일 16시 29분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[4]={0, -1, 0, 1};
int dy[4]={1, 0, -1, 0};
bool safe(int x, int y){
	return min(x, y)>=0&&max(x, y)<=n;
}
int main(){
	scanf("%d%d", &n, &m);
	int x, y, dir;
	x=y=0;
	dir=3;
	for(int i=0;i<m;i++){
		char order[10];
		int in;
		scanf("%s%d", order, &in);
		if(order[0]=='T'){
			if(in==0)
				dir=(dir+1)%4;
			else
				dir=(dir+3)%4;
		}
		else{
			int nx=x+dx[dir]*in;
			int ny=y+dy[dir]*in;
			if(safe(nx, ny)){
				x=nx;
				y=ny;
			}
			else{
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d %d\n", x, y);
	return 0;
}

