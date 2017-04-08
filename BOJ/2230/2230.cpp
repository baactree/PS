// =====================================================================================
// 
//       Filename:  2230.cpp
//        Created:  2017년 04월 08일 12시 54분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
long long arr[100000];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%lld", &arr[i]);
	sort(arr, arr+n);
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<n;i++){
		int idx=lower_bound(arr+i+1, arr+n, arr[i]+m)-arr;
		if(idx!=n){
			ans=min(ans, arr[idx]-arr[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

