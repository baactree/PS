// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 09월 20일 19시 04분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, t;
pair<int, int> arr[1000];
int dp[10000];
int main(){
	scanf("%d%d", &n, &t);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	for(int i=0;i<n;i++)
		for(int j=t;j>=arr[i].first;j--){
			dp[j]=max(dp[j], dp[j-arr[i].first]+arr[i].second);
		}
	printf("%d\n", dp[t]);
	return 0;
}

