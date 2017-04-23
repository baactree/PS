// =====================================================================================
// 
//       Filename:  1103.cpp
//        Created:  2017년 04월 21일 15시 11분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char mat[50][51];
int cnt[3001];
int dist[3001];
bool trip[3001];
int n, m;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	memset(dist, 0x3f, sizeof(dist));
	queue<int> q;
	q.push(0);
	dist[0]=0;
	while(!q.empty()){
		int now=q.front();
		int cost=dist[now];
		int x=now/m;
		int y=now%m;
		trip[now]=false;
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i]*(mat[x][y]-'0');
			int ny=y+dy[i]*(mat[x][y]-'0');
			if(!safe(nx, ny)||mat[nx][ny]=='H'){
				dist[3000]=min(dist[3000], dist[now]-1);
			}
			else{
				int there=nx*m+ny;
				if(dist[there]>dist[now]-1){
					dist[there]=dist[now]-1;
					cnt[there]++;
					if(cnt[there]==n*m){
						printf("-1\n");
						return 0;
					}
					if(!trip[there]){
						q.push(there);
						trip[there]=true;
					}
				}
			}
		}
	}
	printf("%d\n", -dist[3000]);
	return 0;
}

