// =====================================================================================
// 
//       Filename:  2311.cpp
//        Created:  2017년 03월 31일 18시 58분 39초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > adj[1001];
int dist[1001];
int par[1001];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<pair<int, int> > pq;
	pq.push({0, n});
	dist[n]=0;
	while(!pq.empty()){
		int now=pq.top().second;
		int cost=-pq.top().first;
		pq.pop();
		if(dist[now]<cost)
			continue;
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			int there_cost=adj[now][i].second+cost;
			if(dist[there]>there_cost){
				dist[there]=there_cost;
				par[there]=now;
				pq.push({-there_cost, there});
			}
		}
	}
	int temp=1;
	while(par[temp]!=0){
		for(int i=0;i<adj[temp].size();i++){
			int there=adj[temp][i].first;
			if(there==par[temp]){
				adj[temp][i].second*=-1;
				break;
			}
		}
		for(int i=0;i<adj[par[temp]].size();i++){
			int there=adj[par[temp]][i].first;
			if(there==temp){
				adj[par[temp]][i].second=0x3f3f3f3f;
				break;
			}
		}
		temp=par[temp];
	}
	int ans=dist[1];
	memset(dist, 0x3f, sizeof(dist));
	dist[n]=0;
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			int there_cost=adj[now][i].second+dist[now];
			if(there_cost<dist[there]){
				dist[there]=there_cost;
				q.push(there);
			}
		}
	}
	printf("%d\n", ans+dist[1]);
	return 0;
}

