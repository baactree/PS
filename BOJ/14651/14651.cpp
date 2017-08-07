// =====================================================================================
// 
//       Filename:  14651.cpp
//        Created:  2017년 08월 05일 11시 27분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int dp[40000][3];
const int mod=1e9+9;
int main(){
	scanf("%d", &n);
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++){
				if(i==0&&k==0)
					continue;
				dp[i+1][(j+k)%3]=(dp[i+1][(j+k)%3]+dp[i][j])%mod;
			}
	printf("%d\n", dp[n][0]);
	return 0;
}

