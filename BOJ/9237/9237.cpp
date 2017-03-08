// =====================================================================================
// 
//       Filename:  9237.cpp
//        Created:  2017년 03월 08일 20시 26분 14초
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
	int ans=0;
	int cnt=2;
	for(int i=n-1;i>=0;i--){
		ans=max(ans, arr[i]+cnt);
		cnt++;
	}
	printf("%d\n", ans);
	return 0;
}

