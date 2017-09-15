// =====================================================================================
// 
//       Filename:  4179.cpp
//        Created:  2017년 09월 15일 19시 42분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[1005][1005];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int dist[1005][1005];
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	queue<pair<int, int> > jq, fq;
	memset(dist, 0x3f, sizeof(dist));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(mat[i][j]=='J'){
				jq.push({i, j});
				mat[i][j]='.';
				dist[i][j]=0;
			}
			else if(mat[i][j]=='F'){
				fq.push({i, j});
			}
		}
	int ans=0x3f3f3f3f;
	while(!jq.empty()){
		int sz=fq.size();
		while(sz--){
			int x=fq.front().first;
			int y=fq.front().second;
			fq.pop();
			for(int i=0;i<4;i++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(safe(nx, ny)&&mat[nx][ny]=='.'){
					fq.push({nx, ny});
					mat[nx][ny]='F';
				}
			}
		}
		sz=jq.size();
		while(sz--){
			int x=jq.front().first;
			int y=jq.front().second;
			jq.pop();
			for(int i=0;i<4;i++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(safe(nx, ny)){
					if(mat[nx][ny]=='.'&&dist[nx][ny]==0x3f3f3f3f){
						dist[nx][ny]=dist[x][y]+1;
						jq.push({nx, ny});
					}	
				}
				else
					ans=min(ans, dist[x][y]+1);
			}
		}
	}
	if(ans==0x3f3f3f3f)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", ans);
	return 0;
}

