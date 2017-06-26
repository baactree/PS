// =====================================================================================
// 
//       Filename:  2428.cpp
//        Created:  2017년 06월 26일 17시 10분 50초
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
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		arr[i]=in*10;
	}
	sort(arr, arr+n);
	long long int ans=0;
	for(int i=0;i<n;i++){
		int idx=lower_bound(arr, arr+i, arr[i]*0.9)-arr;
		ans+=i-idx;
	}
	printf("%lld\n", ans);
	return 0;
}

