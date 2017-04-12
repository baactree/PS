// =====================================================================================
// 
//       Filename:  14430.cpp
//        Created:  2017-04-12 ¿ÀÈÄ 12:21:09
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[300][300];
int cache[300][300];
int solve(int x, int y){
	if(x==n-1&&y==m-1)
		return mat[x][y];
	int &ret=cache[x][y];
	if(ret!=-1)
		return ret;
	if(x!=n-1)
		ret=max(ret, solve(x+1, y)+mat[x][y]);
	if(y!=m-1)
		ret=max(ret, solve(x, y+1)+mat[x][y]);
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &mat[i][j]);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", solve(0, 0));
	return 0;
}
