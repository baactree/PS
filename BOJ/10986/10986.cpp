// =====================================================================================
// 
//       Filename:  10986.cpp
//        Created:  2017년 03월 31일 02시 15분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1000000];
int cnt[1005];
long long solve(int le, int ri){
	if(le>=ri)
		return arr[le]%m==0;
	int mid=(le+ri)/2;
	long long left_ret=solve(le, mid);
	long long right_ret=solve(mid+1, ri);
	long long ret=0;
	memset(cnt, 0, sizeof(cnt));
	long long sum=0;
	for(int i=mid+1;i<=ri;i++){
		sum+=arr[i];
		cnt[sum%m]++;
	}
	sum=0;
	for(int i=mid;i>=le;i--){
		sum+=arr[i];
		ret+=cnt[(m-(sum)%m)%m];
	}
	return ret+left_ret+right_ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("%lld\n", solve(0, n-1));
	return 0;
}

