// =====================================================================================
// 
//       Filename:  1938.cpp
//        Created:  2017년 04월 15일 11시 08분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dist[50][50][2];
int n;
char mat[55][55];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<n;
}
bool ispossi(int x, int y){
	if(x-1<0||y-1<0||x+1>=n||y+1>=n)
		return false;
	for(int i=x-1;i<=x+1;i++)
		for(int j=y-1;j<=y+1;j++)
			if(mat[i][j]=='1')
				return false;
	return true;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	queue<pair<int, pair<int, int> > > q;
	memset(dist, -1, sizeof(dist));
	int ax, ay, adir;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(mat[i][j]=='B'){
				if(i+1<n&&i-1>=0&&mat[i+1][j]=='B'&&mat[i-1][j]=='B'){
					q.push({0, {i, j}});
					dist[i][j][0]=0;
				}
				if(j+1<n&&j-1>=0&&mat[i][j+1]=='B'&&mat[i][j-1]=='B'){
					q.push({1, {i, j}});
					dist[i][j][1]=0;
				}
			}
			else if(mat[i][j]=='E'){
				if(i+1<n&&i-1>=0&&mat[i+1][j]=='E'&&mat[i-1][j]=='E'){
					ax=i, ay=j, adir=0;
				}
				if(j+1<n&&j-1>=0&&mat[i][j+1]=='E'&&mat[i][j-1]=='E'){
					ax=i, ay=j, adir=1;
				}
			}
	while(!q.empty()){
		int dir=q.front().first;
		int x=q.front().second.first;
		int y=q.front().second.second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(safe(nx, ny)){
				if(dir){
					if(i<2){
						if(mat[nx][ny]!='1'&&ny-1>=0&&mat[nx][ny-1]!='1'&&ny+1<n&&mat[nx][ny+1]!='1'&&dist[nx][ny][dir]==-1){
							dist[nx][ny][dir]=dist[x][y][dir]+1;
							q.push({dir, {nx, ny}});
						}
					}
					else{
						if(ny+dy[i]<n&&ny+dy[i]>=0&&mat[nx][ny+dy[i]]!='1'&&dist[nx][ny][dir]==-1){
							dist[nx][ny][dir]=dist[x][y][dir]+1;
							q.push({dir, {nx, ny}});
						}
					}
				}
				else{
					if(i<2){
						if(nx+dx[i]>=0&&nx+dx[i]<n&&mat[nx+dx[i]][ny]!='1'&&dist[nx][ny][dir]==-1){
							dist[nx][ny][dir]=dist[x][y][dir]+1;
							q.push({dir, {nx, ny}});
						}
					}
					else{
						if(mat[nx][ny]!='1'&&nx+1<n&&nx-1>=0&&mat[nx+1][ny]!='1'&&mat[nx-1][ny]!='1'&&dist[nx][ny][dir]==-1){
							dist[nx][ny][dir]=dist[x][y][dir]+1;
							q.push({dir, {nx, ny}});
						}
					}
				}
			}
		}
		if(ispossi(x, y)&&dist[x][y][1-dir]==-1){
			dist[x][y][1-dir]=dist[x][y][dir]+1;
			q.push({1-dir, {x, y}});
		}
	}
	int ans=dist[ax][ay][adir];
	printf("%d\n", ans==-1?0:ans);
	return 0;
}

