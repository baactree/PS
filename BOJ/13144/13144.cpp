// =====================================================================================
// 
//       Filename:  13144.cpp
//        Created:  2017년 05월 02일 01시 05분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100001];
int main(){
	scanf("%d", &n);
	long long ans=0;
	int st=0;
	for(int i=1;i<=n;i++){
		int in;
		scanf("%d", &in);
		st=max(st, arr[in]);
		ans+=i-st;
		arr[in]=i;
	}
	printf("%lld\n", ans);
	return 0;
}

