// =====================================================================================
// 
//       Filename:  1976.cpp
//        Created:  2017년 03월 26일 22시 16분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[201][201];
int trip[1000];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%d", &mat[i][j]);
			if(mat[i][j]==0)
				mat[i][j]=0x3f3f3f3f;
		}
	for(int i=1;i<=n;i++)
		mat[i][i]=0;
	for(int i=0;i<m;i++)
		scanf("%d", &trip[i]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
	for(int i=0;i<m-1;i++){
		if(mat[trip[i]][trip[i+1]]==0x3f3f3f3f){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}

