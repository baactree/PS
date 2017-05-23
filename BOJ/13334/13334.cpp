// =====================================================================================
// 
//       Filename:  13334.cpp
//        Created:  2017년 05월 23일 11시 32분 52초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<ll, ll> arr[100000];
ll d;
vector<ll> x;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld", &arr[i].first, &arr[i].second);
		if(arr[i].first<arr[i].second)
			swap(arr[i].first, arr[i].second);
		x.push_back(arr[i].second);
	}
	scanf("%lld", &d);
	int ans=0;
	sort(x.begin(), x.end());
	sort(arr, arr+n);
	priority_queue<ll> pq;
	int idx=0;
	for(int i=0;i<x.size();i++){
		while(idx<n&&arr[idx].first<=x[i]+d){
			pq.push(-arr[idx].second);
			idx++;
		}
		while(!pq.empty()&&-pq.top()<x[i])
			pq.pop();
		ans=max(ans, (int)pq.size());
	}
	printf("%d\n", ans);
	return 0;
}

