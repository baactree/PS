// =====================================================================================
// 
//       Filename:  14722.cpp
//        Created:  2017년 09월 30일 15시 57분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1005][1005][3];
int mat[1005][1005];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d", &mat[i][j]);
	memset(dp, -1, sizeof(dp));
	if(mat[0][0]==0)
		dp[0][0][0]=1;
	dp[0][0][2]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				if(dp[i][j][k]==-1)
					continue;
				dp[i+1][j][k]=max(dp[i+1][j][k], dp[i][j][k]);
				dp[i][j+1][k]=max(dp[i][j+1][k], dp[i][j][k]);
			}
			if(dp[i][j][2]!=-1){
				if(mat[i+1][j]==0)
					dp[i+1][j][0]=max(dp[i+1][j][0], dp[i][j][2]+1);
				if(mat[i][j+1]==0)
					dp[i][j+1][0]=max(dp[i][j+1][0], dp[i][j][2]+1);
			}
			if(dp[i][j][0]!=-1){
				if(mat[i+1][j]==1)
					dp[i+1][j][1]=max(dp[i+1][j][1], dp[i][j][0]+1);
				if(mat[i][j+1]==1)
					dp[i][j+1][1]=max(dp[i][j+1][1], dp[i][j][0]+1);
			}
			if(dp[i][j][1]!=-1){
				if(mat[i+1][j]==2)
					dp[i+1][j][2]=max(dp[i+1][j][2], dp[i][j][1]+1);
				if(mat[i][j+1]==2)
					dp[i][j+1][2]=max(dp[i][j+1][2], dp[i][j][1]+1);
			}
		}
	printf("%d\n", max({dp[n-1][n-1][0], dp[n-1][n-1][1], dp[n-1][n-1][2]}));
	return 0;
}

