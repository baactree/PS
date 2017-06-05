// =====================================================================================
// 
//       Filename:  1413.cpp
//        Created:  2017년 06월 05일 17시 55분 45초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll dp[22][22];
ll gcd(ll a, ll b){
	return b?gcd(b, a%b):a;
}
int main(){
	scanf("%d%d", &n, &m);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=dp[i-1][j-1]+(i-1)*dp[i-1][j];
	ll u=0;
	for(int i=1;i<=n;i++)
		u+=dp[n][i];
	ll v=0;
	for(int i=1;i<=m;i++)
		v+=dp[n][i];
	ll g=gcd(u, v);
	printf("%lld/%lld\n", v/g, u/g);
	return 0;
}

