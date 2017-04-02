// =====================================================================================
// 
//       Filename:  1758.cpp
//        Created:  2017년 04월 01일 17시 48분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+=max(arr[n-1-i]-i, 0);
	}
	printf("%lld\n", ans);
	return 0;
}

