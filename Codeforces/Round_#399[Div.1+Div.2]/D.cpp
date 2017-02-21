// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 02월 21일 02시 09분 25초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k, q;
double dp[10001][1001];
int main(){
	scanf("%d%d", &k, &q);
	dp[0][0]=1;
	for(int i=1;i<=10000;i++)
		for(int j=1;j<=k;j++){
			dp[i][j]=dp[i-1][j]*j/k+dp[i-1][j-1]*(k-(j-1))/k;
		}
	for(int i=0;i<q;i++){
		int p;
		scanf("%d", &p);
		for(int j=1;;j++){
			if(dp[j][k]*2000>p-1e-7){
				printf("%d\n", j);
				goto label;
			}
		}
		label:;
	}
	return 0;
}


