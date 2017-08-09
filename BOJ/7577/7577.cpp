// =====================================================================================
// 
//       Filename:  7577.cpp
//        Created:  2017년 08월 10일 00시 06분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int m, n;
int d[50][50];
const int inf=0x3f3f3f3f;
int main(){
	scanf("%d%d", &m, &n);
	memset(d, 0x3f, sizeof(d));
	for(int i=0;i<m;i++){
		d[i][i+1]=1;
		d[i+1][i]=0;
	}
	for(int i=0;i<n;i++){
		int x, y, r;
		scanf("%d%d%d", &x, &y, &r);
		if(d[x-1][y]>r){
			d[x-1][y]=r;
		}
		d[y][x-1]=-r;
	}
	for(int k=0;k<=m;k++)
		for(int i=0;i<=m;i++)
			for(int j=0;j<=m;j++)
				d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
	for(int i=0;i<=m;i++)
		if(d[i][i]<0)
			return !printf("NONE\n");
	for(int i=0;i<m;i++)
		printf("%c", ((d[0][i+1]-d[0][i])==0?'-':'#'));
	return 0;
}

