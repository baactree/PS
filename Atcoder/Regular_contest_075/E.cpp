// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 06월 03일 21시 27분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[200000];
typedef long long ll;
ll solve(int le, int ri){
	if(le==ri)
		return arr[le]>=0;
	int mid=(le+ri)/2;
	ll left_ret=solve(le, mid);
	ll right_ret=solve(mid+1, ri);
	ll ret=0;
	vector<ll> vec;
	ll sum=0;
	for(int i=mid;i>=le;i--){
		sum+=arr[i];
		vec.push_back(sum);
	}
	sort(vec.begin(), vec.end());
	sum=0;
	for(int i=mid+1;i<=ri;i++){
		sum+=arr[i];
		ll cnt=(ll)vec.size()-(lower_bound(vec.begin(), vec.end(), -sum)-vec.begin());
		ret+=cnt;
	}
	return ret+right_ret+left_ret;
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		arr[i]-=k;
	}
	printf("%lld\n", solve(0, n-1));
	return 0;
}

