
// =====================================================================================
// 
//       Filename:  13513.cpp
//        Created:  2017년 04월 30일 23시 22분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
class Sgtree{
public:
	int n;
	vector<pair<int, int> >  tree;
	Sgtree(){}
	Sgtree(int n):n(n){
		tree=vector<pair<int, int> >(4*n, {-0x3f3f3f3f, -0x3f3f3f3f});
	}
	void update(int le, int ri, int val, int nodele, int noderi, int node){
		if(tree[node].second!=-0x3f3f3f3f){
			tree[node].first=max(tree[node].first, tree[node].second);
			if(nodele!=noderi){
				tree[node*2].second=max(tree[node].second, tree[node*2].second);
				tree[node*2+1].second=max(tree[node].second, tree[node*2+1].second);
			}
			tree[node].second=-0x3f3f3f3f;
		}
		if(le>noderi||ri<nodele)
			return;
		if(le<=nodele&&noderi<=ri){
			tree[node].first=max(tree[node].first, val);
			if(nodele!=noderi){
				tree[node*2].second=max(tree[node*2].second, val);
				tree[node*2+1].second=max(tree[node*2+1].second, val);
			}
			return;
		}
		int mid=(nodele+noderi)/2;
		update(le, ri, val, nodele, mid, node*2);
		update(le, ri, val, mid+1, noderi, node*2+1);
	}
	int query(int le, int ri, int nodele, int noderi, int node){
		if(tree[node].second!=-0x3f3f3f3f){
			tree[node].first=max(tree[node].first, tree[node].second);
			if(nodele!=noderi){
				tree[node*2].second=max(tree[node].second, tree[node*2].second);
				tree[node*2+1].second=max(tree[node].second, tree[node*2+1].second);
			}
			tree[node].second=-0x3f3f3f3f;
		}
		if(le>noderi||ri<nodele)
			return -0x3f3f3f3f;
		if(le<=nodele&&noderi<=ri)
			return tree[node].first;
		int mid=(nodele+noderi)/2;
		return max(query(le, ri, nodele, mid, node*2), query(le, ri, mid+1, noderi, node*2+1));
	}
};
int n, m;
vector<pair<int, int> > adj[100001];
vector<int> query[100001];
bool q[200000];
bool trip[100001];
int cnt[100001];
int dist[100001];
Sgtree sgtree;
set<pair<int, int> > s[100001];
int ans[100001];
int get_cnt(int now, int par){
	cnt[now]=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		if(there==par||trip[there])
			continue;
		cnt[now]+=get_cnt(there, now);
	}
	return cnt[now];
}
int get_centroid(int now, int par, int sz){
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		if(there==par||trip[there])
			continue;
		if(cnt[there]>sz)
			return get_centroid(there, now, sz);
	}
	return now;
}
void get_query(int now, int par, int dep, vector<pair<int, pair<int, int> > > & now_query, int num){
	dist[now]=dep;
	for(int i=0;i<query[now].size();i++)
		now_query.push_back({query[now][i], {now, num}});
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int cost=adj[now][i].second;
		if(there==par||trip[there])
			continue;
		get_query(there, now, dep+cost, now_query, num);
	}
}
void solve(int now){
	get_cnt(now, 0);
	int centroid=get_centroid(now, 0, cnt[now]/2);
	trip[centroid]=true;
	vector<pair<int, pair<int, int> > > now_query;
	dist[centroid]=0;
	for(int i=0;i<query[centroid].size();i++)
		now_query.push_back({query[centroid][i], {centroid, 0}});
	for(int i=0;i<adj[centroid].size();i++){
		int there=adj[centroid][i].first;
		int cost=adj[centroid][i].second;
		if(trip[there])
			continue;
		get_query(there, centroid, cost, now_query, i+1);
	}
	map<int, int> mp;
	priority_queue<pair<int, int> > pq;
	sort(now_query.begin(), now_query.end());
	for(int i=0;i<now_query.size();i++){
		int idx=now_query[i].first;
		int nidx;
		if(i+1==now_query.size())
			nidx=n+m-1;
		else
			nidx=now_query[i+1].first-1;
		int vertex=now_query[i].second.first;
		int vertex_num=now_query[i].second.second;
		mp[vertex]++;
		if(mp[vertex]&1)
			s[vertex_num].insert({dist[vertex], vertex});
		else
			s[vertex_num].erase({dist[vertex], vertex});
		if(s[vertex_num].empty())
			ans[vertex_num]=-0x3f3f3f3f;
		else
			ans[vertex_num]=s[vertex_num].rbegin()->first;
		pq.push({ans[vertex_num], vertex_num});
		int update=-0x3f3f3f3f;
		if(mp[centroid]&1)
			update=0;
		while(!pq.empty()&&ans[pq.top().second]!=pq.top().first)
			pq.pop();
		if(!pq.empty()){
			pair<int, int> pick=pq.top();
			pq.pop();
			while(!pq.empty()&&(pq.top().second==pick.second||ans[pq.top().second]!=pq.top().first))
				pq.pop();
			if(!pq.empty())
				update=max(update, pick.first+pq.top().first);
			else if(mp[centroid]&1)
				update=max(update, pick.first);
			pq.push(pick);
		}
		sgtree.update(idx, nidx, update, 0, n+m-1, 1);
	}
	s[0].clear();
	ans[0]=-0x3f3f3f3f;
	for(int i=0;i<adj[centroid].size();i++){
		s[i+1].clear();
		ans[i+1]=-0x3f3f3f3f;
	}
	for(int i=0;i<adj[centroid].size();i++){
		int there=adj[centroid][i].first;
		if(trip[there])
			continue;
		solve(there);
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n-1;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	scanf("%d", &m);
	for(int i=0;i<n;i++)
		query[i+1].push_back(i);
	for(int i=0;i<m;i++){
		int a;
		scanf("%d", &a);
		if(a==1){
			int b;
			scanf("%d", &b);
			query[b].push_back(i+n);
		}
		else
			q[i+n]=true;
	}
	sgtree=Sgtree(n+m);
	solve(1);
	int now=-0x3f3f3f3f;
	for(int i=0;i<m+n;i++){
		if(q[i]){
			int ans=sgtree.query(i, i, 0, m+n-1, 1);
			if(ans==-0x3f3f3f3f)
				printf("-1\n");
			else
				printf("%d\n", ans);
		}
	}
	return 0;
}

