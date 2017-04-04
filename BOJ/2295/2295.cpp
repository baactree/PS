// =====================================================================================
// 
//       Filename:  2295.cpp
//        Created:  2017년 04월 04일 17시 16분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[1000];
set<ll> s;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%lld", &arr[i]);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++)
			s.insert(arr[i]+arr[j]);
	}
	ll ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(s.find(arr[j]-arr[i])!=s.end())
				ans=max(ans, arr[j]);
		}
	printf("%d\n", ans);
	return 0;
}

