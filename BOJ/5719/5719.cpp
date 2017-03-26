// =====================================================================================
// 
//       Filename:  5719.cpp
//        Created:  2017년 03월 26일 22시 50분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int s, d;
int mat[505][505];
vector<int> dist;
vector<stack<int> > par;
int main(){
	while(true){
		scanf("%d%d", &n, &m);
		if(n==0)
			break;
		scanf("%d%d", &s, &d);
		memset(mat, 0x3f, sizeof(mat));
		for(int i=0;i<m;i++){
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			mat[a][b]=d;
		}
		dist=vector<int>(n+1, 0x3f3f3f3f);
		par=vector<stack<int> >(n+1);
		dist[s]=0;
		priority_queue<pair<int, int> > pq;
		pq.push({0, s});
		while(!pq.empty()){
			int now=pq.top().second;
			int cost=-pq.top().first;
			pq.pop();
			if(dist[now]<cost)
				continue;
			for(int i=0;i<n;i++){
				if(i==now||mat[now][i]==0x3f3f3f3f)
					continue;
				int there=i;
				int there_cost=mat[now][i]+cost;
				if(dist[there]>there_cost){
					par[there]=stack<int>();
					dist[there]=there_cost;
					par[there].push(now);
					pq.push({-there_cost, there});
				}
				else if(dist[there]==there_cost)
					par[there].push(now);
			}
		}
		queue<int> q;
		q.push(d);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			if(now==s)
				continue;
			while(!par[now].empty()){
				int there=par[now].top();
				par[now].pop();
				mat[there][now]=0x3f3f3f3f;
				q.push(there);
			}
		}
		dist=vector<int>(n+1, 0x3f3f3f3f);
		dist[s]=0;
		pq.push({0, s});
		while(!pq.empty()){
			int now=pq.top().second;
			int cost=-pq.top().first;
			pq.pop();
			if(dist[now]<cost)
				continue;
			for(int i=0;i<n;i++){
				if(i==now||mat[now][i]==0x3f3f3f3f)
					continue;
				int there=i;
				int there_cost=mat[now][i]+cost;
				if(dist[there]>there_cost){
					dist[there]=there_cost;
					pq.push({-there_cost, there});
				}
			}
		}
		printf("%d\n", dist[d]==0x3f3f3f3f?-1:dist[d]);
	}
	return 0;
}

