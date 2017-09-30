// =====================================================================================
// 
//       Filename:  4172.cpp
//        Created:  2017년 09월 30일 15시 32분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
const int mod=1000000;
int main(){
	dp[0]=1;
	for(int i=1;i<=1000000;i++)
		dp[i]=(dp[(int)(i-sqrt(i))]+dp[(int)(log(i))]+dp[(int)(i*sin(i)*sin(i))])%mod;
	int n;
	while(true){
		scanf("%d", &n);
		if(n==-1)
			break;
		printf("%d\n", dp[n]);
	}
	return 0;
}

