#include <bits/stdc++.h>
using namespace std;
class Dinic{
public:
	const int inf = 2e9+5;
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
	int n;
	vector<vector<Edge*> > adj;
	vector<int> level;
	vector<int> idx;
	Dinic(int n):n(n){
		level=vector<int>(n);
		idx=vector<int>(n);
		adj=vector<vector<Edge*> > (n);
	}
	~Dinic(){
		for(int i=0;i<n;i++)
			for(int j=0;j<adj[i].size();j++)
				delete adj[i][j];
	}
	void make_edge(int u, int v, int capacity){
		Edge *uv=new Edge(v, capacity);
		Edge *vu=new Edge(u, 0);
		uv->rev=vu;
		vu->rev=uv;
		adj[u].push_back(uv);
		adj[v].push_back(vu);
	}
	bool bfs(int s, int t){
		fill(level.begin(), level.end(), -1);
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
		return level[t]==-1;
	}
	int dfs(int now, int t, int amount){
		if(now==t)
			return amount;
		for(int &i=idx[now];i<adj[now].size();i++){
			int there=adj[now][i]->v;
			int sub=adj[now][i]->residual();
			if(level[there]==level[now]+1&&sub>0){
				int temp=dfs(there, t, min(amount, sub));
				if(temp>0){
					adj[now][i]->flow+=temp;
					adj[now][i]->rev->flow-=temp;
					return temp;
				}
			}
		}
		return 0;
	}
	int flow(int s, int t){
		int max_flow=0;
		while(true){
			if(bfs(s, t))
				break;
			fill(idx.begin(), idx.end(), 0);
			while(true){
				int flow=dfs(s, t, inf);
				if(flow==0)
					break;
				max_flow+=flow;
			}
		}
		return max_flow;
	}
	vector<int> find(int s){
		vector<int> ret;
		fill(level.begin(),level.end(),-1);
		queue<int> q;
		q.push(s);
		level[s]=0;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(auto x:adj[now]){
				int there=x->v;
				int r=x->residual();
				int c=x->capacity;
				if(r>0&&level[there]==-1){
					q.push(there);
					level[there]=0;
				}
			}
		}
		for(int i=2;i<n;i+=2)
			if(!level[i]&&level[i+1]==-1)
				ret.push_back(i/2);
		return ret;
	}
};
int n,m;
const int inf=2e9+5;
int main(){
	scanf("%d%d",&n,&m);
	Dinic dinic(n*2+2);
	int st,fi;
	int s,t;
	s=0;
	t=1;
	scanf("%d%d",&st,&fi);
	dinic.make_edge(s,st*2,inf);
	dinic.make_edge(fi*2+1,t,inf);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		dinic.make_edge(i*2,i*2+1,x);
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		dinic.make_edge(a*2+1,b*2,inf);
		dinic.make_edge(b*2+1,a*2,inf);
	}
	dinic.flow(s,t);
	vector<int> ans=dinic.find(s);
	sort(ans.begin(),ans.end());
	for(auto x:ans)
		printf("%d ",x);
	printf("\n");
	return 0;
}