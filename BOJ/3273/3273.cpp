// =====================================================================================
// 
//       Filename:  3273.cpp
//        Created:  2017년 03월 23일 11시 31분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, x;
map<int, int> m;
int arr[100000];
int main(){
	scanf("%d", &n);
	long long ans=0;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &x);
	for(int i=0;i<n;i++){
		ans+=m[x-arr[i]];
		m[arr[i]]++;
	}
	printf("%lld\n", ans);
	return 0;
}

