// =====================================================================================
// 
//       Filename:  2234.cpp
//        Created:  2017년 03월 17일 17시 29분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[50][50];
int color[50][50];
vector<int> s;
int dx[4]={0, -1, 0, 1};
int dy[4]={-1, 0, 1, 0};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int dfs(int x, int y, int c){
	color[x][y]=c;
	int ret=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&(mat[x][y]&(1<<i))==0&&color[nx][ny]==-1){
			ret+=dfs(nx, ny, c);
		}
	}
	return ret;
}
int main(){
	scanf("%d%d", &m, &n);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &mat[i][j]);
	memset(color, -1, sizeof(color));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(color[i][j]==-1){
				int now = dfs(i, j, s.size());
				s.push_back(now);
			}
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(i+1<n&&color[i+1][j]!=color[i][j])
				ans=max(ans, s[color[i][j]]+s[color[i+1][j]]);
			if(j+1<m&&color[i][j]!=color[i][j+1])
				ans=max(ans, s[color[i][j]]+s[color[i][j+1]]);
		}
	printf("%d\n%d\n%d\n", s.size(), *max_element(s.begin(), s.end()), ans);
	return 0;
}

