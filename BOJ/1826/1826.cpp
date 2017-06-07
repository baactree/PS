// =====================================================================================
// 
//       Filename:  1826.cpp
//        Created:  2017년 06월 07일 17시 07분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[10000];
int l, p;
bool possi(int x){
	int ri=p;
	int idx=0;
	priority_queue<int> pq;
	for(int i=0;i<x;i++){
		for(;idx<n;idx++){
			if(arr[idx].first<=ri)
				pq.push(arr[idx].second);
			else
				break;
		}
		if(pq.empty())
			continue;
		int now=pq.top();
		pq.pop();
		ri+=now;
	}
	return ri>=l;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	sort(arr, arr+n);
	scanf("%d%d", &l, &p);
	int le, ri, mid, ans;
	ans=-1;
	le=0;
	ri=n;
	while(le<=ri){
		int mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	printf("%d\n", ans);
	return 0;
}

