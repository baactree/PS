// =====================================================================================
// 
//       Filename:  13301.cpp
//        Created:  2017년 03월 13일 23시 14분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long int dp[81];
int main(){
	dp[0]=dp[1]=1;
	int n;
	scanf("%d", &n);
	for(int i=2;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-2];
	printf("%lld\n", dp[n]*2+dp[n-1]*2);
	return 0;
}

