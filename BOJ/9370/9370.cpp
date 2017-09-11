// =====================================================================================
// 
//       Filename:  9370.cpp
//        Created:  2017년 09월 11일 22시 36분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int s, g, h;
vector<pair<int, int> > adj[2005];
int dist[2005];
int trip[2005];
int arr[100];
vector<int> ans;
void dfs(int now, int st){
	trip[now]=true;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int weight=adj[now][i].second;
		if(dist[now]==dist[there]+weight){
			if((now==g&&there==h)||(now==h&&there==g))
				ans.push_back(st);
			if(!trip[there])
				dfs(there, st);
		}
	}
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		for(int i=0;i<2005;i++)
			adj[i].clear();
		ans.clear();
		scanf("%d%d%d", &n, &m, &t);
		scanf("%d%d%d", &s, &g, &h);
		for(int i=0;i<m;i++){
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			adj[a].push_back({b, d});
			adj[b].push_back({a, d});
		}
		for(int i=0;i<t;i++){
			scanf("%d", &arr[i]);
		}
		memset(dist, 0x3f, sizeof(dist));
		dist[s]=0;
		priority_queue<pair<int, int> > pq;
		pq.push({0, s});
		while(!pq.empty()){
			int cost=-pq.top().first;
			int now=pq.top().second;
			pq.pop();
			if(dist[now]<cost)
				continue;
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i].first;
				int there_cost=adj[now][i].second+cost;
				if(dist[there]>there_cost){
					dist[there]=there_cost;
					pq.push({-there_cost, there});
				}
			}
		}
		for(int i=0;i<t;i++){
			memset(trip, 0, sizeof(trip));
			dfs(arr[i], arr[i]);
		}
		sort(ans.begin(), ans.end());
		for(int i=0;i<ans.size();i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}

