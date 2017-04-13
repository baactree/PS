// =====================================================================================
// 
//       Filename:  11562.cpp
//        Created:  2017년 04월 12일 11시 33분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[251][251];
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	memset(mat, 0x3f, sizeof(mat));
	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(c)
			mat[a][b]=mat[b][a]=0;
		else{
			mat[a][b]=0;
			mat[b][a]=1;
		}
	}
	for(int i=1;i<=n;i++)
		mat[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
	int k;
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", mat[a][b]);
	}
	return 0;
}

