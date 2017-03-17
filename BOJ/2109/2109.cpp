// =====================================================================================
// 
//       Filename:  2109.cpp
//        Created:  2017년 03월 17일 17시 00분 00초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[10000];
int dp[10005];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].second, &arr[i].first);
	sort(arr, arr+n);
	for(int i=0;i<n;i++){
		for(int j=10000;j>0;j--){
			if(arr[i].first>=j){
				dp[j+1]=max(dp[j+1], dp[j]+arr[i].second);
			}
		}
	}
	int ans=0;
	for(int i=0;i<10005;i++)
		ans=max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}

