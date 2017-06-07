// =====================================================================================
// 
//       Filename:  10423.cpp
//        Created:  2017년 06월 07일 16시 58분 39초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int, int> > adj[1005];
bool trip[1005];
int main(){
	scanf("%d%d%d", &n, &m, &k);	
	for(int i=0;i<k;i++){
		int in;
		scanf("%d", &in);
		trip[in]=true;
	}
	for(int i=0;i<m;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	priority_queue<pair<int, int> > pq;
	for(int i=1;i<=n;i++){
		if(trip[i]){
			for(int j=0;j<adj[i].size();j++){
				int there=adj[i][j].first;
				int weight=adj[i][j].second;
				pq.push({-weight, there});
			}
		}
	}
	long long ans=0;
	while(!pq.empty()){
		int now=pq.top().second;
		int cost=-pq.top().first;
		pq.pop();
		if(trip[now])
			continue;
		ans+=cost;
		trip[now]=true;
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			int weight=adj[now][i].second;
			if(!trip[there]){
				pq.push({-weight, there});
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

