// =====================================================================================
// 
//       Filename:  14495.cpp
//        Created:  2017년 05월 01일 14시 59분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[117];
int n;
int main(){
	scanf("%d", &n);
	dp[1]=dp[2]=dp[3]=1;
	for(int i=4;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-3];
	printf("%lld\n", dp[n]);
	return 0;
}

