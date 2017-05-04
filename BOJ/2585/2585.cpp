// =====================================================================================
// 
//       Filename:  2585.cpp
//        Created:  2017년 05월 04일 23시 00분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<int, int> arr[1005];
int dist[1005];
typedef long long ll;
bool possi(ll m){
	memset(dist, -1, sizeof(dist));
	dist[n-2]=0;
	queue<int> q;
	q.push(n-2);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(dist[now]==k+1)
			continue;
		for(int i=0;i<n;i++){
			if(i==now)
				continue;
			ll x=arr[now].first-arr[i].first;
			ll y=arr[now].second-arr[i].second;
			ll d=x*x+y*y;
			if(d<=100*m*m&&dist[i]==-1){
				dist[i]=dist[now]+1;
				q.push(i);
			}
		}
	}
	return dist[n-1]!=-1;
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	arr[n]={0, 0};
	arr[n+1]={10000, 10000};
	n+=2;
	ll le, ri, mid, ans;
	le=0;ri=1e7;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else 
			le=mid+1;
	}
	printf("%lld\n", ans);
	return 0;
}

