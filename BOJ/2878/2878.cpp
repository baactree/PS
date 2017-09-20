// =====================================================================================
// 
//       Filename:  2878.cpp
//        Created:  2017년 09월 16일 18시 02분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int n, m;
ll arr[100000];
bool possi(ll x){
	ll sum=0;
	for(int i=0;i<n;i++){
		if(arr[i]>x){
			sum+=arr[i]-x;
		}
	}
	return sum<=m;
}
int main(){
	scanf("%d%d", &m, &n);
	for(int i=0;i<n;i++){
		scanf("%llu", &arr[i]);
	}
	ll le, ri, mid, ans;
	le=0;
	ri=2e9;
	ans=0;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else le=mid+1;
	}
	ll cnt=m;
	priority_queue<ll> pq;
	for(int i=0;i<n;i++){
		if(arr[i]>ans){
			cnt-=arr[i]-ans;
			pq.push(ans);
		}
		else{
			pq.push(arr[i]);
		}
	}
	ll s=0;
	while(!pq.empty()){
		ll now=pq.top();
		pq.pop();
		if(cnt){
			s+=(now-1)*(now-1);
			cnt--;
		}
		else
			s+=now*now;
	}
	printf("%llu\n", s);
	return 0;
}

