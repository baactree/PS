// =====================================================================================
// 
//       Filename:  3190.cpp
//        Created:  2017년 04월 05일 01시 13분 52초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int mat[105][105];
pair<int, int> apple[100];
int l;
pair<int, int> order[101];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0, 1};
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n+2;i++){
		mat[0][i]=1;
		mat[n+1][i]=1;
		mat[i][0]=1;
		mat[i][n+1]=1;
	}
	for(int i=0;i<k;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		mat[a][b]=2;
	}
	scanf("%d", &l);
	for(int i=0;i<l;i++){
		char in[2];
		scanf("%d%s", &order[i].first, in);
		order[i].second=in[0]=='D'?-1:1;
	}
	order[l]={10000, 'D'};
	int x, y, dir;
	x=y=1;
	dir=3;
	int ans=0;
	queue<pair<int, int> > q;
	q.push({1, 1});
	mat[1][1]=1;
	for(int i=0;i<=l;i++){
		for(int j=1;j<=order[i].first-ans;j++){
			int nx=x+dx[dir];
			int ny=y+dy[dir];
			if(mat[nx][ny]==1){
				printf("%d\n", ans+j);
				return 0;
			}
			if(mat[nx][ny]!=2){
				int tx=q.front().first;
				int ty=q.front().second;
				q.pop();
				mat[tx][ty]=0;
			}
			mat[nx][ny]=1;
			q.push({nx, ny});
			x=nx;
			y=ny;
		}
		ans+=order[i].first-ans;
		dir=(dir+order[i].second+4)%4;
	}
	return 0;
}

