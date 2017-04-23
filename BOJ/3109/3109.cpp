// =====================================================================================
// 
//       Filename:  3109.cpp
//        Created:  2017년 04월 23일 12시 15분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool trip[10000][500];
char in[10000][505];
int r, c;
bool dfs(int x, int y){
	if(y==c-1)
		return true;
	trip[x][y]=true;
	if(x-1>=0&&!trip[x-1][y+1]&&dfs(x-1, y+1))
		return true;
	if(!trip[x][y+1]&&dfs(x, y+1))
		return true;
	if(x+1<r&&!trip[x+1][y+1]&&dfs(x+1, y+1))
		return true;
	return false;
}
int main(){
	scanf("%d%d", &r, &c);
	for(int i=0;i<r;i++)
		scanf("%s", in[i]);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			if(in[i][j]=='x')
				trip[i][j]=1;
		}
	int ans=0;
	for(int i=0;i<r;i++){
		if(dfs(i, 0))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

