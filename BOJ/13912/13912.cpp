// =====================================================================================
// 
//       Filename:  13912.cpp
//        Created:  2017년 09월 19일 02시 09분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int h;
const int mod=1e9+7;
typedef long long ll;
ll dp[3000];
ll c[3000][3000];
int main(){
	scanf("%d", &h);
	dp[0]=1;
	for(int i=1;i<3000;i++){
		c[i][0]=1;
		c[i][i]=1;
		for(int j=1;j<i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	for(int i=1;i<=h;i++){
		int k=(1<<(i+1))-2;
		dp[i]=(((c[k][k/2]*dp[i-1])%mod)*dp[i-1])%mod;
	}
	printf("%lld\n", dp[h]);
	return 0;
}

