// =====================================================================================
// 
//       Filename:  F.cpp
//        Created:  2017년 08월 12일 14시 34분 57초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
struct Mcmf{
	struct Edge{
		int v, c, f, w;
		Edge *r;
		Edge(){}
		Edge(int v, int c, int w):v(v), c(c), w(w), f(0), r(0){}
		int get_residual(){
			if(f<0)
				return -f;
			return c-f;
		}
		int get_cost(){
			if(f<0)
				return -r->w;
			return w;
		}
		void push(int amt){
			f+=amt;
			r->f-=amt;
		}
	};
	vector<vector<Edge*> > adj;
	vector<int> dist, par, amt, idx, trip;
	int n;
	Mcmf(){}
	Mcmf(int v):n(v){
		adj.resize(v+1);
		dist.resize(v+1);
		par.resize(v+1);
		amt.resize(v+1);
		idx.resize(v+1);
		trip.resize(v+1);
	}
	~Mcmf(){
		for(int i=0;i<=n;i++)
			for(int j=0;j<adj[i].size();j++)
				delete adj[i][j];
		adj.clear();
		dist.clear();
		par.clear();
		amt.clear();
		idx.clear();
		trip.clear();
	}
	void make_edge(int u, int v, int c, int w){
		Edge *uv=new Edge(v, c, w);
		Edge *vu=new Edge(u, 0, 0);
		uv->r=vu;
		vu->r=uv;
		adj[u].push_back(uv);
		adj[v].push_back(vu);
	}
	int flow(int s, int t){
		int ret=0;
		while(true){
			fill(dist.begin(), dist.end(), inf);
			fill(trip.begin(), trip.end(), 0);
			dist[s]=0;
			trip[s]=true;
			amt[s]=inf;
			queue<int> q;
			q.push(s);
			while(!q.empty()){
				int now=q.front();
				q.pop();
				trip[now]=false;
				for(int i=0;i<adj[now].size();i++){
					int there=adj[now][i]->v;
					int r=adj[now][i]->get_residual();
					int w=adj[now][i]->get_cost();
					if(r>0&&dist[there]>dist[now]+w){
						dist[there]=dist[now]+w;
						par[there]=now;
						amt[there]=min(amt[now], r);
						idx[there]=i;
						if(!trip[there]){
							trip[there]=true;
							q.push(there);
						}
					}
				}
			}
			if(dist[t]==inf)
				break;
			ret+=amt[t]*dist[t];
			int now=t;
			while(now!=s){
				int p=par[now];
				adj[p][idx[now]]->push(amt[t]);
				now=p;
			}
		}
		return ret;
	}
};
vector<int> adj1[105], adj2[105];
int cache[105][105];
int solve(int x, int y, int parx, int pary){
	int &ret=cache[x][y];
	if(ret!=-1)
		return ret;
	vector<int> left, right;
	for(int i=0;i<adj1[x].size();i++){
		int there=adj1[x][i];
		if(there==parx)
			continue;
		left.push_back(there);
	}
	for(int i=0;i<adj2[y].size();i++){
		int there=adj2[y][i];
		if(there==pary)
			continue;
		right.push_back(there);
	}
	int temp;
	if(left.size()==0||right.size()==0)
		return ret=1;
	int s, t;
	s=0;
	t=left.size()+right.size()+1;
	for(int i=0;i<left.size();i++)
		for(int j=0;j<right.size();j++)
			solve(left[i], right[j], x, y);
	Mcmf mcmf(t);
	for(int i=0;i<left.size();i++)
		for(int j=0;j<right.size();j++)
			mcmf.make_edge(i+1, j+1+left.size(), 1, -solve(left[i], right[j], x, y));
	for(int i=0;i<left.size();i++)
		mcmf.make_edge(s, i+1, 1, 0);
	for(int i=0;i<right.size();i++)
		mcmf.make_edge(i+1+left.size(), t, 1, 0);
	ret=1+-mcmf.flow(s, t);
	return ret;
}
int solution(int n1, vector<vector<int>> g1, int n2, vector<vector<int>> g2) {
	for(int i=0;i<105;i++){
		adj1[i].clear();
		adj2[i].clear();
	}
	for(int i=0;i<g1.size();i++){
		int u=g1[i][0];
		int v=g1[i][1];
		adj1[u].push_back(v);
		adj1[v].push_back(u);
	}
	for(int i=0;i<g2.size();i++){
		int u=g2[i][0];
		int v=g2[i][1];
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}
	memset(cache, -1, sizeof(cache));
    return solve(1, 1, 0, 0);
}
int main(){
	int n, m;
	vector<vector<int> > g1, g2;
	scanf("%d", &n);
	for(int i=1;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		g1.push_back(vector<int>({a, b}));
	}
	scanf("%d", &m);
	for(int i=1;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		g2.push_back(vector<int>({a, b}));
	}
	cout<<solution(n, g1, m, g2)<<endl;
	return 0;
}
