// =====================================================================================
// 
//       Filename:  5820.cpp
//        Created:  2017년 04월 28일 23시 01분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<pair<int, int> > adj[200005];
int sub_cnt[200005];
bool trip[200005];
map<int, int> m;
int get_cnt(int now, int par){
	sub_cnt[now]=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		if(there==par||trip[there])
			continue;
		sub_cnt[now]+=get_cnt(there, now);
	}
	return sub_cnt[now];
}
int get_centroid(int now, int par, int sz){
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		if(there==par||trip[there])
			continue;
		if(sub_cnt[there]>sz)
			return get_centroid(there, now, sz);
	}
	return now;
}
void get_ans(int now, int par, vector<pair<int, int> > &vec, int dep, int cost){
	if(cost>k)
		return;
	vec.push_back({cost, dep});
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int c=adj[now][i].second;
		if(there==par||trip[there])
			continue;
		get_ans(there, now, vec, dep+1, cost+c);
	}
}
int solve(int now){
	get_cnt(now, -1);
	int centroid=get_centroid(now, -1, sub_cnt[now]/2);
	trip[centroid]=true;
	int ret=0x3f3f3f3f;
	map<int, int> m;
	m[0]=0;
	for(int i=0;i<adj[centroid].size();i++){
		int there=adj[centroid][i].first;
		int cost=adj[centroid][i].second;
		if(trip[there])
			continue;
		vector<pair<int, int> > temp;
		get_ans(there, centroid, temp, 1, cost);
		for(int j=0;j<temp.size();j++){
			int t=temp[j].first;
			int c=temp[j].second;
			if(m.count(k-t)!=0)
				ret=min(ret, m[k-t]+c);
		}
		for(int j=0;j<temp.size();j++){
			int t=temp[j].first;
			int c=temp[j].second;
			if(m.count(t)==0)
				m[t]=c;
			else
				m[t]=min(m[t], c);
		}
	}
	for(int i=0;i<adj[centroid].size();i++){
		int there=adj[centroid][i].first;
		if(trip[there])
			continue;
		ret=min(ret, solve(there));
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n-1;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	int ans=solve(0);
	printf("%d\n", ans==0x3f3f3f3f?-1:ans);
	return 0;
}

