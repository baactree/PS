// =====================================================================================
// 
//       Filename:  3114.cpp
//        Created:  2017년 05월 02일 00시 46분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int r, c;
int mat[1505][1505];
int suma[1505][1505];
int sumb[1505][1505];
int cache[1505][1505];
int solve(int x, int y){
	if(x==r&&y==c)
		return 0;
	int &ret=cache[x][y];
	if(ret!=-1)
		return ret;
	if(x!=r)
		ret=max(ret, solve(x+1, y)+sumb[x][c]-sumb[x][y]);
	if(y!=c)
		ret=max(ret, solve(x, y+1)+suma[r][y]-suma[x][y]);
	if(x!=r&&y!=c)
		ret=max(ret, solve(x+1, y+1)+sumb[x][c]-sumb[x][y]+suma[r][y]-suma[x][y]);
	return ret;
}
int main(){
	scanf("%d%d", &r, &c);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++){
			char temp[2];
			int idx;
			scanf("%1s%d", temp, &idx);
			if(temp[0]=='A')
				mat[i][j]=idx;
			else
				mat[i][j]=-idx;
		}
	for(int j=1;j<=c;j++)
		for(int i=1;i<=r;i++)
			suma[i][j]=suma[i-1][j]+max(0, mat[i][j]);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			sumb[i][j]=sumb[i][j-1]+max(0,(-mat[i][j]));
	memset(cache, -1, sizeof(cache));
	printf("%d\n", solve(1, 1));
	return 0;
}

