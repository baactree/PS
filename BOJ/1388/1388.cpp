// =====================================================================================
// 
//       Filename:  1388.cpp
//        Created:  2017년 04월 23일 19시 57분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[100][105];
bool trip[100][100];
void dfs(int x, int y, int mode){
	trip[x][y]=true;
	if(mode){
		if(y+1<m&&!trip[x][y+1]&&mat[x][y+1]=='-'){
			dfs(x, y+1, mode);
		}
	}
	else{
		if(x+1<n&&!trip[x+1][y]&&mat[x+1][y]=='|'){
			dfs(x+1, y, mode);
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%s", &mat[i]);
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!trip[i][j]){
				ans++;
				dfs(i,j, mat[i][j]=='-');
			}
	printf("%d\n", ans);
	return 0;
}

