// =====================================================================================
// 
//       Filename:  13549.cpp
//        Created:  2017년 04월 10일 18시 39분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int dist[300000];
int main(){
	scanf("%d%d", &n, &k);
	memset(dist, 0x3f, sizeof(dist));
	dist[n]=0;
	priority_queue<pair<int, int> > pq;
	pq.push({0, n});
	while(!pq.empty()){
		int now=pq.top().second;
		int cost=-pq.top().first;
		pq.pop();
		if(dist[now]<cost)
			continue;
		if(now*2<300000&&dist[now*2]>cost){
			dist[now*2]=cost;
			pq.push({-cost, now*2});
		}
		if(now+1<300000&dist[now+1]>cost+1){
			dist[now+1]=cost+1;
			pq.push({-dist[now+1], now+1});
		}
		if(now-1>=0&&dist[now-1]>cost+1){
			dist[now-1]=cost+1;
			pq.push({-dist[now-1], now-1});
		}
	}
	printf("%d\n", dist[k]);
	return 0;
}

