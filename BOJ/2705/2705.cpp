// =====================================================================================
// 
//       Filename:  2705.cpp
//        Created:  2017년 05월 21일 13시 36분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dp[1005];
int main(){
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=1000;i++)
		for(int j=0;j*2<=i;j++){
			dp[i]+=dp[j];
		}
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}

