// =====================================================================================
// 
//       Filename:  6144.cpp
//        Created:  2017년 09월 20일 21시 05분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> arr[4000];
int dp[13000];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	for(int i=0;i<n;i++)
		for(int j=m;j>=arr[i].first;j--)
			dp[j]=max(dp[j], dp[j-arr[i].first]+arr[i].second);
	printf("%d\n", dp[m]);
	return 0;
}

