// =====================================================================================
// 
//       Filename:  13458.cpp
//        Created:  2017년 03월 26일 22시 34분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000000];
int b, c;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	scanf("%d%d", &b, &c);
	long long cnt=0;
	for(int i=0;i<n;i++){
		cnt++;
		double now=max(0, arr[i]-b);
		cnt+=ceil(now/c);
	}
	printf("%lld\n", cnt);
	return 0;
}

