// =====================================================================================
// 
//       Filename:  2316.cpp
//        Created:  2017년 04월 02일 20시 47분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Edge{
	int v, f, c;
	Edge* rv;
	Edge():v(0), f(0), c(0), rv(0){}
	Edge(int v, int c):v(v), f(0), c(c){}
};
vector<Edge*> adj[805];
void make_edge(int a, int b, int c){
	Edge *ab, *ba;
	ab=new Edge(b, c);
	ba=new Edge(a, 0);
	ab->rv=ba;
	ba->rv=ab;
	adj[a].push_back(ab);
	adj[b].push_back(ba);
}
bool trip[805];
int par[805];
int num[805];
int flow(int s, int t){
	int ret=0;
	while(true){
		memset(trip, 0, sizeof(trip));
		memset(par, -1, sizeof(par));
		queue<int> q;
		trip[s]=true;
		q.push(s);
		int	min_flow=0x3f3f3f3f;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i]->v;
				int sub=adj[now][i]->c-adj[now][i]->f;
				if(trip[there]||sub<=0)
					continue;
				trip[there]=true;
				q.push(there);
				par[there]=now;
				num[there]=i;
				min_flow=min(min_flow, sub);
			}
		}
		if(!trip[t])
			break;
		int now=t;
		while(par[now]!=-1){
			int p=par[now];
			int pidx=num[now];
			adj[p][pidx]->f+=min_flow;
			adj[p][pidx]->rv->f-=min_flow;
			now=par[now];
		}
		ret+=min_flow;
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		make_edge(a*2+1, b*2, 1);
		make_edge(b*2+1, a*2, 1);
	}
	for(int i=1;i<=n;i++){
		make_edge(i*2, i*2+1, 1);
	}
	printf("%d\n", flow(3, 4));
	return 0;
}

