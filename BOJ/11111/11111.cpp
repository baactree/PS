// =====================================================================================
// 
//       Filename:  11111.cpp
//        Created:  2017년 09월 19일 21시 41분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct MCMF {
	const int INF=0x3f3f3f3f;
	int V, totalFlow, totalCost;
	struct Edge {
		int target, capacity, cost, flow;
		Edge* dual;
		Edge(int target, int capacity, int cost) :
			target(target), capacity(capacity), cost(cost), flow(0) {}
		inline int residual() const {
			if (flow < 0)
				return -flow;
			return capacity - flow;
		}
		inline int getCost()const {
			if (flow < 0)
				return -dual->cost;
			return cost;
		}
		void push(int amt) {
			flow += amt;
			dual->flow -= amt;
		}
	};
	vector<vector<Edge*> > adj;
	MCMF(int n) :V(n), totalFlow(0), totalCost(0), adj(n) {}
	~MCMF() {
		for (int i = 0; i < V; i++)
			for (int j = 0; j < adj[i].size(); j++)
				delete adj[i][j];
	}
	void setEdge(int u, int v, int uvCapacity, int uvCost) {
		Edge* uv = new Edge(v, uvCapacity, uvCost);
		Edge* vu = new Edge(u, 0, 0);
		uv->dual = vu;
		vu->dual = uv;
		adj[u].push_back(uv);
		adj[v].push_back(vu);
	}
	int improve(int s, int t) {
		while (true) {
			vector<int> dist(V, INF), par(V, -1), edgeNo(V, -1), capa(V, -1);
			par[s] = s;
			dist[s] = 0;
			capa[s] = INF;
			queue<int> q;
			q.push(s);
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				for (int i = 0; i < adj[now].size(); i++) {
					Edge* e = adj[now][i];
					if (e->residual() <= 0)
						continue;
					int thereCost = dist[now] + e->getCost();
					if (dist[e->target] > thereCost) {
						dist[e->target] = thereCost;
						q.push(e->target);
						par[e->target] = now;
						edgeNo[e->target] = i;
						capa[e->target] = min(capa[now], e->residual());
					}
				}
			}
		if (dist[t] == INF)
				break;
			int here = t, amt = capa[t];
			while (here != s) {
				int there = par[here];
				adj[there][edgeNo[here]]->push(amt);
				here = there;
			}
			totalFlow += amt;
			totalCost += dist[t] * amt;
		}
		return totalCost;
	}
};
const int inf=0x3f3f3f3f;
int n, m;
char mat[55][55];
char cost[300][300];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int main(){
	cost['A']['A']=10;
	cost['A']['B']=8;
	cost['A']['C']=7;
	cost['A']['D']=5;
	cost['A']['F']=1;

	cost['B']['A']=8;
	cost['B']['B']=6;
	cost['B']['C']=4;
	cost['B']['D']=3;
	cost['B']['F']=1;

	cost['C']['A']=7;
	cost['C']['B']=4;
	cost['C']['C']=3;
	cost['C']['D']=2;
	cost['C']['F']=1;

	cost['D']['A']=5;
	cost['D']['B']=3;
	cost['D']['C']=2;
	cost['D']['D']=2;
	cost['D']['F']=1;

	cost['F']['A']=1;
	cost['F']['B']=1;
	cost['F']['C']=1;
	cost['F']['D']=1;
	cost['F']['F']=0;
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	MCMF mcmf(n*m+2);
	int s=n*m;
	int t=n*m+1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if((i+j)&1){
				mcmf.setEdge(i*m+j, t, 1, 0);	
			}
			else{
				mcmf.setEdge(s, i*m+j, 1, 0);	
				mcmf.setEdge(i*m+j, t, 1, 0);
				for(int k=0;k<4;k++){
					int x=i+dx[k];
					int y=j+dy[k];
					if(safe(x, y)){
						mcmf.setEdge(i*m+j, x*m+y, inf, -cost[mat[i][j]][mat[x][y]]);
					}
				}
			}
		}
	printf("%d\n", -mcmf.improve(s, t));
	return 0;
}

