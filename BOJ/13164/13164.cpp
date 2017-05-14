// =====================================================================================
// 
//       Filename:  13164.cpp
//        Created:  2017년 05월 14일 17시 40분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[300000];
int diff[300000];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	for(int i=1;i<n;i++)
		diff[i-1]=arr[i]-arr[i-1];
	sort(diff, diff+n-1);
	long long ans=0;
	for(int i=0;i<n-1-(k-1);i++)
		ans+=diff[i];
	printf("%lld\n", ans);
	return 0;
}

