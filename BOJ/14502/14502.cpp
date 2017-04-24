// =====================================================================================
// 
//       Filename:  14502.cpp
//        Created:  2017년 04월 24일 23시 37분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[8][8];
bool trip[8][8];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int dfs(int x, int y){
	trip[x][y]=true;
	int ret=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&!trip[nx][ny]&&mat[nx][ny]==0)
			ret+=dfs(nx, ny);
	}
	return ret;
}
int solve(){
	memset(trip, 0, sizeof(trip));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j]==2&&!trip[i][j])
				dfs(i, j);
	int ret=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j]==0&&!trip[i][j])
				ret+=dfs(i, j);
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &mat[i][j]);
	int ans=0;
	for(int x1=0;x1<n;x1++)
		for(int y1=0;y1<m;y1++){
			if(mat[x1][y1]!=0)
				continue;
			for(int x2=0;x2<n;x2++)
				for(int y2=0;y2<m;y2++){
					if(mat[x2][y2]!=0)
						continue;
					if(x1==x2&&y1==y2)
						continue;
					for(int x3=0;x3<n;x3++)
						for(int y3=0;y3<m;y3++){
							if(mat[x3][y3]!=0)
								continue;
							if(x1==x3&&y1==y3)
								continue;
							if(x2==x3&&y2==y3)
								continue;
							mat[x1][y1]=mat[x2][y2]=mat[x3][y3]=1;
							ans=max(ans, solve());
							mat[x1][y1]=mat[x2][y2]=mat[x3][y3]=0;
						}
				}
		}
	printf("%d\n", ans);
	return 0;
}

