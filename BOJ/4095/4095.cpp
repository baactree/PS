// =====================================================================================
// 
//       Filename:  4095.cpp
//        Created:  2017년 04월 28일 13시 23분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[1005][1005];
int dp[1005][1005];
int n, m;
int main(){
	while(true){
		scanf("%d%d", &n, &m);
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d", &mat[i][j]);
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(mat[i][j]==0)
					dp[i][j]=0;
				else{
					dp[i][j]=min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
				}
				ans=max(ans, dp[i][j]);
			}
		printf("%d\n", ans);
	}
	return 0;
}

