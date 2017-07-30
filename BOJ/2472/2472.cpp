// =====================================================================================
// 
//       Filename:  2472.cpp
//        Created:  2017년 07월 30일 17시 16분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int st[3];
int dist[3][100005];
vector<pair<int, int> > adj[100005];
bool ans[100005];
int tree[400005];
int sz;
void dijk(int k){
	dist[k][st[k]]=0;
	priority_queue<pair<int, int> > pq;
	pq.push({0, st[k]});
	while(!pq.empty()){
		int now=pq.top().second;
		int cost=-pq.top().first;
		pq.pop();
		if(cost>dist[k][now])
			continue;
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			int there_cost=cost+adj[now][i].second;
			if(dist[k][there]>there_cost){
				dist[k][there]=there_cost;
				pq.push({-there_cost, there});
			}
		}
	}
}
void update(int idx, int val){
	idx+=sz;
	while(idx){
		tree[idx]=min(tree[idx], val);
		idx>>=1;
	}
}
int query(int a, int b){
	a+=sz;
	b+=sz;
	int ret=0x3f3f3f3f;
	while(a<=b){
		if(a&1)
			ret=min(ret, tree[a++]);
		if(!(b&1))
			ret=min(ret, tree[b--]);
		a>>=1;
		b>>=1;
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<3;i++)
		scanf("%d", &st[i]);
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	memset(dist, 0x3f, sizeof(dist));
	for(int i=0;i<3;i++)
		dijk(i);
	vector<pair<pair<int, int>, pair<int, int> > > vec;
	vector<int> idx;
	for(int i=1;i<=n;i++){
		vec.push_back({{dist[0][i],dist[1][i]},  {dist[2][i], i}});
		idx.push_back(dist[1][i]);
	}
	sort(vec.begin(), vec.end());
	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());
	memset(tree, 0x3f, sizeof(tree));
	sz=1;
	while(sz<idx.size())
		sz*=2;
	int pre=0;
	for(int i=0;i<n;i++){
		bool flag=true;
		int tidx=lower_bound(idx.begin(), idx.end(), vec[i].first.second)-idx.begin();
		int now=query(0, tidx-1);
		if(now<vec[i].second.first)
				flag=false;
		ans[vec[i].second.second]=flag;
		if(i+1==n||vec[i].first.first!=vec[i+1].first.first){
			for(int j=pre;j<=i;j++){
				int pidx=lower_bound(idx.begin(), idx.end(), vec[j].first.second)-idx.begin();
				update(pidx, vec[j].second.first);
			}
			pre=i+1;
		}
	}
	int t;
	scanf("%d", &t);
	while(t--){
		int q;
		scanf("%d", &q);
		printf("%s\n", ans[q]?"YES":"NO");
	}
	return 0;
}

