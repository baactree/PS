// =====================================================================================
// 
//       Filename:  11058.cpp
//        Created:  2017년 04월 15일 12시 48분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll dp[105][105];
ll calc(int x){
	ll ret=0;
	for(int i=0;i<n;i++)
		ret=max(ret, dp[x][i]);
	return ret;
}
int main(){
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(dp[i][j]==-1)
				continue;
			dp[i+1][j]=max(dp[i+1][j], dp[i][j]+1);
			dp[i+2][i]=max(dp[i+2][i], dp[i][j]);
			dp[i+1][j]=max(dp[i+1][j], dp[i][j]+calc(j));
		}
	ll ans=0;
	for(int i=0;i<n;i++)
		ans=max(ans, dp[n][i]);
	printf("%lld\n", ans);
	return 0;
}

