// =====================================================================================
// 
//       Filename:  2560.cpp
//        Created:  2017년 04월 08일 13시 03분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b, d, n;
const int shift=20000;
int dp[1000001+shift];
int z[1000001+shift];
int main(){
	scanf("%d%d%d%d", &a, &b, &d, &n);
	dp[0+shift]=z[0+shift]=1;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum=(sum-z[i-b+shift]+z[i-a+shift]+1000)%1000;
		z[i+shift]=sum;
		dp[i+shift]=(dp[i-1+shift]-z[i-d+shift]+z[i+shift]+1000)%1000;
	}
	printf("%d\n", dp[n+shift]);
	return 0;
}

