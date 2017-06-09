// =====================================================================================
// 
//       Filename:  2015.cpp
//        Created:  2017년 06월 09일 16시 06분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[200000];
long long solve(int le, int ri){
	if(le==ri)
		return arr[le]==k;
	int mid=(le+ri)/2;
	long long left_ret=solve(le, mid);
	long long right_ret=solve(mid+1, ri);
	map<long long, long long> mp;
	long long sum=0;
	for(int i=mid;i>=le;i--){
		sum+=arr[i];
		mp[sum]++;
	}
	sum=0;
	long long ret=0;
	for(int i=mid+1;i<=ri;i++){
		sum+=arr[i];
		ret+=mp[k-sum];
	}
	return left_ret+right_ret+ret;
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("%lld\n", solve(0, n-1));
	return 0;
}

