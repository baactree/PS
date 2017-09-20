// =====================================================================================
// 
//       Filename:  H.cpp
//        Created:  2017년 09월 17일 00시 22분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
struct Edge{
	int v, c, f, r;
	Edge(){}
	Edge(int v, int c):v(v), c(c), f(0), r(0){}
	int get_residual(){
		if(f<0)
			return -f;
		return c-f;
	}
};
int sum=0;
vector<Edge> adj[2500];
void make_edge(int u, int v, int c){
	Edge uv(v, c);
	Edge vu(u, 0);
	uv.r=adj[v].size();
	vu.r=adj[u].size();
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
void make_edge(int u, int v, int l, int r, int s, int t){
	sum+=l;
	make_edge(u, v, r-l);
	make_edge(s, v, l);
	make_edge(u, t, l);
}
int level[2500];
int idx[2500];
bool bfs(int s, int t){
	memset(level, -1, sizeof(level));
	level[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].v;
			int r=adj[now][i].get_residual();
			if(level[there]==-1&&r>0){
				level[there]=level[now]+1;
				q.push(there);
			}
		}
	}
	return level[t]==-1;
}
int dfs(int now, int t, int amt){
	if(now==t)
		return amt;
	for(int &i=idx[now];i<adj[now].size();i++){
		int there=adj[now][i].v;
		int r=adj[now][i].get_residual();
		if(level[there]==level[now]+1&&r>0){
			int temp=dfs(there, t, min(amt, r));
			if(temp>0){
				adj[now][i].f+=temp;
				adj[there][adj[now][i].r].f-=temp;
				return temp;
			}
		}
	}
	return 0;
}
int flow(int s, int t){
	int ret=0;
	while(true){
		if(bfs(s, t))
			break;
		memset(idx, 0, sizeof(idx));
		while(true){
			int f=dfs(s, t, inf);
			if(f==0)
				break;
			ret+=f;
		}
	}
	return ret;
}

int m, n, p1, p2;
vector<int> vertex[105];
bool chk[105];
int main(){
	scanf("%d%d%d%d", &m, &n, &p1, &p2);
	int s, t, ns, nt;
	s=0;
	t=1;
	ns=2;
	nt=3;
	//3+[1, m] = 멤버
	//3+m+[1, n] = 일
	for(int i=1;i<=n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		make_edge(3+m+i, t, a, b, ns, nt);
	}
	int cnt=3+m+n+1;
	for(int i=1;i<=m;i++){
		int k;
		scanf("%d", &k);
		memset(chk, 0, sizeof(chk));
		while(k--){
			int d, r1, r2;
			scanf("%d%d%d", &d, &r1, &r2);
			int len=r2-r1+1;
			make_edge(3+i, cnt, 0, len-d, ns, nt);
			for(int j=r1;j<=r2;j++){
				chk[j]=true;
				make_edge(cnt, 3+m+j, 0, 1, ns, nt);
			}
			vertex[i].push_back(cnt);
			cnt++;
		}
		for(int j=1;j<=n;j++)
			if(!chk[j])
				make_edge(3+i, 3+m+j, 1, 1, ns, nt);
		make_edge(s, 3+i, p1, p2, ns, nt);
	}
	make_edge(t, s, inf);
	if(flow(ns, nt)==sum){
		printf("1\n");
		for(int i=1;i<=m;i++){
			vector<int> out;
			for(int j=0;j<vertex[i].size();j++){
				int now=vertex[i][j];
				for(int ii=0;ii<adj[now].size();ii++){
					int v=adj[now][ii].v;
					if(v>=3+m+1&&v<=3+m+n&&adj[now][ii].f==0)
						out.push_back(v-3-m);
				}
			}
			sort(out.begin(), out.end());
			printf("%d", out.size());
			for(int i=0;i<out.size();i++)
				printf(" %d", out[i]);
			printf("\n");
		}
	}
	else
		return !printf("-1\n");
	return 0;
}

