// =====================================================================================
// 
//       Filename:  13119.cpp
//        Created:  2017년 06월 04일 18시 05분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int h[100005];
vector<vector<char> > mat;
int main(){
	scanf("%d%d%d", &n, &m, &x);
	mat=vector<vector<char> >(n+1, vector<char>(m+1, '.'));
	for(int i=1;i<=m;i++)
		scanf("%d", &h[i]);
	for(int i=1;i<=m;i++){
		for(int j=0;j<h[i];j++)
			mat[n-j][i]='#';
		if(mat[n-x+1][i]=='.')
			mat[n-x+1][i]='-';
		else
			mat[n-x+1][i]='*';
		if(i%3==0)
			for(int j=h[i];j<x-1;j++)
				mat[n-j][i]='|';
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%c", mat[i][j]);
		printf("\n");
	}
	return 0;
}

