// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 07월 30일 23시 44분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[40000];
int dp[55][40000];
int idx[55][40000];
void solve(int t, int s, int e, int p, int q){
	if(s>e)
		return;
	int m=(s+e)>>1;
	set<int> check;
	for(int i=min(m-1, q);i>=p;i--){
		check.insert(arr[i]);
		int v=dp[t-1][i]+check.size();
		if(dp[t][m]<v){
			dp[t][m]=v;
			idx[t][m]=i;		
		}
	}
	check.clear();
	solve(t, s, m-1, p, idx[t][m]);
	solve(t, m+1, e, idx[t][m], q);
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	for(int i=1;i<=k;i++)
		solve(i, 0, n, 0, n-1);
	int ans=k;
	for(int i=0;i<=n;i++)
		ans=max(ans, dp[k][i]);
	printf("%d\n", ans);
	return 0;
}
