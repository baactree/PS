// =====================================================================================
// 
//       Filename:  2405.cpp
//        Created:  2017년 05월 22일 18시 31분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
long long arr[100000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%lld", &arr[i]);
	sort(arr, arr+n);
	long long ans=0;
	for(int i=1;i<n-1;i++){
		ans=max(ans, abs(arr[0]+arr[i]+arr[i+1]-arr[i]*3));
		ans=max(ans, abs(arr[i]+arr[i-1]+arr[n-1]-arr[i]*3));
	}
	printf("%lld\n", ans);
	return 0;
}

