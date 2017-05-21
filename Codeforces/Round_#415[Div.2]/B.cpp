// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 05월 21일 21시 07분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, f;
pair<int, int> arr[100000];
pair<int, int> t[100000];
int main(){
	scanf("%d%d", &n, &f);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	for(int i=0;i<n;i++){
		t[i].second=min(arr[i].first, arr[i].second);
		t[i].first=min(arr[i].first*2, arr[i].second)-t[i].second;
	}
	sort(t, t+n);
	long long ans=0;
	for(int i=0;i<n;i++){
		if(i<f)
			ans+=t[n-1-i].first+t[n-1-i].second;
		else
			ans+=t[n-1-i].second;
	}
	printf("%lld\n", ans);
	return 0;
}

