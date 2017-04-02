// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 04월 02일 15시 32분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000];
int temp[100000];
typedef long long ll;
ll solve(int le, int ri){
	if(le==ri)
		return temp[le];
	int mid=(le+ri)/2;
	ll left_ret=solve(le, mid);
	ll right_ret=solve(mid+1, ri);
	ll rodd_max, reven_max;
	rodd_max=reven_max=-0x3f3f3f3f3f3f3f3f;
	ll sum=0;
	for(int i=mid+1;i<=ri;i++){
		sum+=(i&1)?temp[i]:-temp[i];
		rodd_max=max(rodd_max, sum);
		reven_max=max(reven_max, -sum);
	}
	sum=0;
	ll lodd_max, leven_max;
	lodd_max=leven_max=-0x3f3f3f3f3f3f3f3f;
	for(int i=mid;i>=le;i--){
		sum+=(i&1)?temp[i]:-temp[i];
		lodd_max=max(lodd_max, sum);
		leven_max=max(leven_max, -sum);
	}
	ll ret=max(lodd_max+rodd_max, leven_max+reven_max);
	return max(ret, max(left_ret, right_ret));
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		if(i!=0){
			temp[i-1]=abs(arr[i]-arr[i-1]);
		}
	}
	printf("%lld\n", solve(0, n-2));
	return 0;
}

