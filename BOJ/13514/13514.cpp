// =====================================================================================
// 
//       Filename:  13514.cpp
//        Created:  2017년 04월 29일 18시 05분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[100005];
vector<pair<int, int> > q[100005];
int ans[100005];
int check[100005];
int cnt[100005];
int trip[100005];
int dist[100005];
int get_cnt(int now, int par){
	cnt[now]=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par||trip[there])
			continue;
		cnt[now]+=get_cnt(there, now);
	}
	return cnt[now];
}
int get_centroid(int now, int par, int sz){
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par||trip[there])
			continue;
		if(cnt[there]>sz)
			return get_centroid(there, now, sz);
	}
	return now;
}
void get_query(int now, int par, int dep, vector<pair<int, pair<int, int> > > &query){
	dist[now]=dep;
	for(int i=0;i<q[now].size();i++)
		query.push_back({q[now][i].second, {q[now][i].first, now}});
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par||trip[there])
			continue;
		get_query(there, now, dep+1, query);
	}
}
void solve(int now){
	get_cnt(now, 0);
	int centroid=get_centroid(now, 0, cnt[now]/2);
	trip[centroid]=true;
	vector<pair<int, pair<int, int > > > query;
	get_query(centroid, 0, 0, query);
	sort(query.begin(), query.end());
	priority_queue<pair<int, int> > pq;
	map<int, int> m;
	for(int i=0;i<query.size();i++){
		int a=query[i].second.first;
		int b=query[i].second.second;
		int idx=query[i].first;
		if(a==1){
			pq.push({-dist[b], b});
			m[b]++;
		}
		else{
			while(!pq.empty()){
				int now=pq.top().second;
				if(m[now]%2==0)
					pq.pop();
				else
					break;
			}
			if(!pq.empty())
				ans[idx]=min(ans[idx], -pq.top().first+dist[b]);
		}
	}
	for(int i=0;i<adj[centroid].size();i++){
		int there=adj[centroid][i];
		if(trip[there])
			continue;
		solve(there);
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n-1;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		q[b].push_back({a, i});
		if(a==2)
			check[i]=true;
	}
	memset(ans, 0x3f, sizeof(ans));
	solve(1);
	for(int i=0;i<m;i++)
		if(check[i])
			printf("%d\n", ans[i]==0x3f3f3f3f?-1:ans[i]);
	return 0;
}

