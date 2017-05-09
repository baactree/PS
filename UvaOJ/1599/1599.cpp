// =====================================================================================
// 
//       Filename:  1599.cpp
//        Created:  2017년 05월 09일 15시 59분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > adj[100001];
bool trip[100001];
int dist[100001];
vector<int> ans;
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}
int main(){
	while(scanf("%d%d", &n, &m)!=EOF){
		for(int i=0;i<=n;i++)
			adj[i].clear();
		for(int i=0;i<m;i++){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			adj[a].push_back({b, c});
			adj[b].push_back({a, c});
		}
		for(int i=1;i<=n;i++)
			sort(adj[i].begin(), adj[i].end(), cmp);
		memset(dist, -1, sizeof(dist));
		dist[n]=0;
		queue<int> q;
		q.push(n);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i].first;
				int col=adj[now][i].second;
				if(dist[there]!=-1)
					continue;
				q.push(there);
				dist[there]=dist[now]+1;
			}
		}
		memset(trip, 0, sizeof(trip));
		ans=vector<int>(dist[1], 0x3f3f3f3f);
		q.push(1);
		trip[1]=true;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			if(now==n)
				continue;
			int min_color=0x3f3f3f3f;
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i].first;
				int color=adj[now][i].second;
				if(dist[there]+1==dist[now])
					min_color=min(min_color, color);
			}
			int idx=dist[1]-dist[now];
			ans[idx]=min(ans[idx], min_color);
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i].first;
				int color=adj[now][i].second;
				if(dist[there]+1==dist[now]&&color==min_color&&!trip[there]){
					trip[there]=true;
					q.push(there);
				}
			}
		}
		printf("%d\n", ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d%c", ans[i], " \n"[i+1==ans.size()]);
	}
	return 0;
}

