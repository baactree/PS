// =====================================================================================
// 
//       Filename:  5911.cpp
//        Created:  2017년 06월 15일 04시 06분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005][2];
pair<int, int> arr[1000];
int n, b;
const int inf=0x3f3f3f3f;
int main(){
	scanf("%d%d", &n, &b);
	b;
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<2;k++){
				if(dp[i][j][k]==inf)
					continue;
				dp[i+1][j+1][k]=min((long long)dp[i+1][j+1][k], (long long)dp[i][j][k]+arr[i].first+arr[i].second);
				dp[i+1][j][k]=min(dp[i+1][j][k], dp[i][j][k]);
				if(k==0)
					dp[i+1][j+1][k+1]=min((long long)dp[i+1][j+1][k+1], (long long)dp[i][j][k]+arr[i].first/2+arr[i].second);
			}
	int ans=0;
	for(int j=0;j<=n;j++)
		for(int k=0;k<2;k++)
			if(dp[n][j][k]<=b)
				ans=max(ans, j);
	printf("%d\n", ans);
	return 0;
}

