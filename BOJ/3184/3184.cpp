// =====================================================================================
// 
//       Filename:  3184.cpp
//        Created:  2017년 09월 11일 23시 23분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[300][300];
bool trip[300][300];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<=n+1&&y>=0&&y<=m+1;
}
pair<int, int> dfs(int x, int y){
	trip[x][y]=true;
	pair<int, int> ret={0, 0};
	if(mat[x][y]=='v')
		ret.second++;
	else if(mat[x][y]=='o')
		ret.first++;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&mat[nx][ny]!='#'&&!trip[nx][ny]){
			auto temp=dfs(nx, ny);
			ret.first+=temp.first;
			ret.second+=temp.second;
		}
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		scanf("%s", mat[i]+1);
	int cnt=0;
	int a, b;
	a=0;
	b=0;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			if(!trip[i][j]){
				auto temp=dfs(i, j);
				if(cnt){
					if(temp.first>temp.second){
						a+=temp.first;
					}
					else{
						b+=temp.second;
					}
				}
				cnt++;
			}
	printf("%d %d\n", a, b);
	return 0;
}

