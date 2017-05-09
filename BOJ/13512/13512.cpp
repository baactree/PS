// =====================================================================================
// 
//       Filename:  13512.cpp
//        Created:  2017년 05월 09일 17시 39분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
int color[100001];
int cnt;
vector<int> adj[100001];
int depth[100001];
int subtree_cnt[100001];
vector<vector<int> > h_p;
int h_p_idx[100001];
set<pair<int, int> > s[100001];
int dfs(int now, int par, int dep){
	depth[now]=dep;
	subtree_cnt[now]=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		subtree_cnt[now]+=dfs(there, now, dep+1);
	}
	return subtree_cnt[now];
}
void make_hd(int root){
	queue<pair<int, int> > q;
	q.push({root, 0});
	while(!q.empty()){
		int now=q.front().first;
		int par=q.front().second;
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i];
			if(there==par)
				continue;
			q.push({there, now});
		}
		if(now==root)
			continue;
		if(subtree_cnt[now]*2>=subtree_cnt[par]&&par!=root){
			int hidx=h_p_idx[now]=h_p_idx[par];
			h_p[hidx].push_back(now);
		}
		else{
			h_p_idx[now]=h_p.size();
			h_p.push_back(vector<int>(2));
			h_p.back()[0]=par;
			h_p.back()[1]=now;
		}
	}
}
int find_idx(int hidx,int v){
    int top=h_p[hidx][0];
    return depth[v]-depth[top]-1;
}
void update(int v){
	color[v]^=1;
	if(color[v]){
		int hidx=h_p_idx[v];
		s[hidx].insert({find_idx(hidx,v), v});
	}
	else{
		int hidx=h_p_idx[v];
		s[hidx].erase({find_idx(hidx,v), v});
	}
}
int query(int v){
	int ret=-1;
	while(true){
		int hidx=h_p_idx[v];
		if(!s[hidx].empty()){
			auto k=*s[hidx].begin();
			if(k.first<=find_idx(hidx,v))
                ret=k.second;
		}
		if(v==1)
			break;
		v=h_p[hidx][0];
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i+1<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0, 0);
	make_hd(1);
    scanf("%d",&m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(a==1)
			update(b);
		else
			printf("%d\n", query(b));
	}
	return 0;
}
