// =====================================================================================
// 
//       Filename:  13161.cpp
//        Created:  2017년 04월 02일 22시 36분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[501];
int mat[501][501];
vector<int> a;
vector<int> b;
vector<int> c;
const int inf=0x3f3f3f3f;
struct Edge{
	int v, capacity, flow;
	Edge *rev;
	Edge(int v, int capacity):v(v), capacity(capacity), flow(0), rev(0){}
	inline int residual(){
		if(flow<0)
			return -flow;
		return capacity-flow;
	}
};
vector<Edge*> adj[505];
void make_edge(int u, int v, int capacity){
	Edge *uv=new Edge(v, capacity);
	Edge *vu=new Edge(u, 0);
	uv->rev=vu;
	vu->rev=uv;
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
int level[505];
int trip[505];
int work[505];
int dfs(int v, int amt,int t){
	if(v==t)
		return amt;
	int ret=0;
	for(int &i=work[v];i<adj[v].size();i++){
		int there=adj[v][i]->v;
		int sub=adj[v][i]->residual();
		if(level[there]==level[v]+1&&sub>0){
			int temp=dfs(there, min(amt, sub), t);
			if(temp>0){
				adj[v][i]->flow+=temp;
				adj[v][i]->rev->flow-=temp;
				return temp;
			}
		}
	}
	return ret;
}
int dinic(int s, int t){
	int ret=0;
	while(true){
		memset(level, -1, sizeof(level));
		level[s]=0;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i]->v;
				int sub=adj[now][i]->residual();
				if(level[there]==-1&&sub>0){
					level[there]=level[now]+1;
					q.push(there);
				}
			}
		}
		if(level[t]==-1)
			break;
		memset(work, 0, sizeof(work));
		while(true){
			int flow=dfs(s, inf, t);
			if(flow==0)
				break;
			ret+=flow;
		}
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &arr[i]);
		if(arr[i]==0)
			c.push_back(i);
		else if(arr[i]==1)
			a.push_back(i);
		else
			b.push_back(i);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d", &mat[i][j]);
	for(int i=0;i<a.size();i++){
		make_edge(0, a[i], inf);
		for(int j=0;j<c.size();j++)
			make_edge(a[i], c[j], mat[a[i]][c[j]]);
	}
	for(int i=0;i<c.size();i++)
		for(int j=i+1;j<c.size();j++){
			make_edge(c[i], c[j], mat[c[i]][c[j]]);
			make_edge(c[j], c[i], mat[c[j]][c[i]]);
		}
	for(int i=0;i<b.size();i++){
		make_edge(b[i], n+1, inf);
		for(int j=0;j<c.size();j++)
			make_edge(c[j], b[i], mat[c[j]][b[i]]);
	}
	int ans=0;
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++)
			make_edge(a[i], b[j], mat[a[i]][b[j]]);
	printf("%d\n", dinic(0, n+1));
	queue<int> q;
	memset(trip, 0, sizeof(trip));
	q.push(0);
	trip[0]=true;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i]->v;
			int sub=adj[now][i]->residual();
			if(!trip[there]&&sub>0){
				trip[there]=true;
				q.push(there);
			}
		}
	}
	for(int i=0;i<c.size();i++){
		if(trip[c[i]])
			a.push_back(c[i]);
		else
			b.push_back(c[i]);
	}
	for(int i=0;i<a.size();i++)
		printf("%d ", a[i]);
	printf("\n");
	for(int i=0;i<b.size();i++)
		printf("%d ", b[i]);
	printf("\n");
	return 0;
}

