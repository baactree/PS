// =====================================================================================
// 
//       Filename:  8394.cpp
//        Created:  2017년 02월 21일 15시 57분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int dp[10000005];
int main(){
	scanf("%d", &n);
	dp[0]=1;
	for(int i=0;i<n;i++){
		dp[i+1]+=dp[i];
		dp[i+1]%=10;
		dp[i+2]+=dp[i];
		dp[i+2]%=10;
	}
	printf("%d\n", dp[n]);
	return 0;
}

