// =====================================================================================
// 
//       Filename:  10251.cpp
//        Created:  2017년 03월 26일 21시 51분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, l, g;
int gr[100][100];
int gc[100][100];
int dp[105][105][300][2];
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d%d%d%d", &n, &m, &l, &g);
		for(int i=0;i<n;i++)
			for(int j=0;j<m-1;j++)
				scanf("%d", &gr[i][j]);
		for(int i=0;i<n-1;i++)
			for(int j=0;j<m;j++)
				scanf("%d", &gc[i][j]);
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0][0][0]=0;
		dp[0][0][0][1]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				for(int k=0;k<250;k++){
					if(i+1!=n){
						dp[i+1][j][k][0]=min(dp[i+1][j][k][0], dp[i][j][k][0]+gc[i][j]);
						dp[i+1][j][k+1][0]=min(dp[i+1][j][k+1][0], dp[i][j][k][1]+gc[i][j]);
					}
					if(j+1!=m){
						dp[i][j+1][k][1]=min(dp[i][j+1][k][1], dp[i][j][k][1]+gr[i][j]);
						dp[i][j+1][k+1][1]=min(dp[i][j+1][k+1][1], dp[i][j][k][0]+gr[i][j]);
					}
				}
			}
		int ans=0x3f3f3f3f;
		for(int i=0;i<250;i++){
			if(dp[n-1][m-1][i][0]<=g)
				ans=min(ans, i);
			if(dp[n-1][m-1][i][1]<=g)
				ans=min(ans, i);
		}
		printf("%d\n", ans==0x3f3f3f3f?-1:(n-1)*l+(m-1)*l+ans);
	}
	return 0;
}

