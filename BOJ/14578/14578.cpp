// =====================================================================================
// 
//       Filename:  14578.cpp
//        Created:  2017년 09월 22일 20시 37분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
const int mod=1e9+7;
ll dp[100005];
int main(){
	scanf("%d", &n);
	ll ans=1;
	dp[0]=0;
	dp[1]=0;
	dp[2]=1;
	for(int i=3;i<=n;i++){
		dp[i]=((i-1)*(dp[i-1]+dp[i-2])%mod)%mod;
	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	printf("%lld\n", (ans*dp[n])%mod);
	return 0;
}

