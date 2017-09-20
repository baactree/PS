// =====================================================================================
// 
//       Filename:  2411.cpp
//        Created:  2017년 09월 18일 22시 15분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int a, b;
int mat[105][105];
int dp[2][105][10005];;
int main(){
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for(int i=0;i<a;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		mat[x][y]=1;
	}
	for(int i=0;i<b;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		mat[x][y]=2;
	}
	if(mat[1][1]==1)
		dp[1][1][1]=1;
	else
		dp[1][1][0]=1;
	for(int i=1;i<=n;i++){
		int now=i&1;
		int pre=(i+1)&1;
		for(int j=1;j<=m;j++){
			if(i==1&&j==1)
				continue;
			for(int k=0;k<=a;k++){
				if(mat[i][j]==1&&k>0){
					dp[now][j][k]=dp[now][j-1][k-1]+dp[pre][j][k-1];
				}
				else if(mat[i][j]==0){
					dp[now][j][k]=dp[now][j-1][k]+dp[pre][j][k];
				}
				else{
					dp[now][j][k]=0;
				}
			}
		}
	}
	printf("%d\n", dp[n&1][m][a]);
	return 0;
}

