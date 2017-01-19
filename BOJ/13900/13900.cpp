// =====================================================================================
// 
//       Filename:  13900.cpp
//        Created:  2017년 01월 19일 16시 42분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100000];
int main(){
	long long sum=0;
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	long long ans=0;
	for(int i=0;i<N;i++){
		ans+=arr[i]*(sum-arr[i]);
		sum-=arr[i];
	}
	printf("%lld\n", ans);
	return 0;
}

