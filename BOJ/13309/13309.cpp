// =====================================================================================
// 
//       Filename:  13309.cpp
//        Created:  2017년 08월 10일 18시 17분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
struct Idt{
	vector<int> tree;
	int sz;
	Idt(){}
	Idt(int n){
		sz=1;
		while(sz<n)
			sz<<=1;
		tree=vector<int>(n*4, 0);
	}
	void update(int idx, int val){
		idx+=sz;
		while(idx){
			tree[idx]=max(tree[idx], val);
			idx>>=1;
		}
	}
	int query(int a, int b){
		a+=sz;
		b+=sz;
		int ret=0;
		while(a<=b){
			if(a&1)
				ret=max(ret, tree[a++]);
			if(!(b&1))
				ret=max(ret, tree[b--]);
			a>>=1;
			b>>=1;
		}
		return ret;
	}
};
int n, q;
int depth[200005];
int cnt[200005];
vector<vector<int> > hld;
int hidx[200005];
int par[200005][18];
vector<Idt> hidt;
vector<int> adj[200005];
void dfs(int now, int dep){
	depth[now]=dep;
	cnt[now]=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		par[there][0]=now;
		for(int i=1;i<18;i++)
			par[there][i]=par[par[there][i-1]][i-1];
		dfs(there, dep+1);
		cnt[now]+=cnt[there];
	}
}
void make_hd(int root){
	hld.push_back(vector<int>(1, root));
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i];
			if(cnt[there]*2>=cnt[now]){
				hld[hidx[now]].push_back(there);
				hidx[there]=hidx[now];
			}
			else{
				hidx[there]=hld.size();
				hld.push_back(vector<int>({now, there}));
			}
			q.push(there);
		}
	}
	for(int i=0;i<hld.size();i++)
		hidt.push_back(Idt(hld[i].size()));
}
int get_kidx(int x){
	return depth[x]-depth[hld[hidx[x]][0]];
}
int lca(int x, int y){
	if(depth[x]<depth[y])
		swap(x, y);
	for(int i=17;i>=0;i--)
		if(depth[x]-depth[y]>=1<<i)
			x=par[x][i];
	if(x==y)
		return x;
	for(int i=17;i>=0;i--)
		if(par[x][i]!=par[y][i]){
			x=par[x][i];
			y=par[y][i];
		}
	return par[x][0];
}
void update(int x){
	hidt[hidx[x]].update(get_kidx(x), inf);
}
int hq(int u, int v){
	if(u==v)
		return 0;
	if(hidx[u]==hidx[v])
		return hidt[hidx[u]].query(get_kidx(u)+1, get_kidx(v));
	return max(hq(u, hld[hidx[v]][0]), hidt[hidx[v]].query(1, get_kidx(v)));
}
bool query(int u, int v){
	int l=lca(u, v);
	int r=max(hq(l, u), hq(l, v));
	return r==0;
}
int main(){
	scanf("%d%d", &n, &q);
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d", &x);
		adj[x].push_back(i);
	}
	dfs(1, 0);
	make_hd(1);
	while(q--){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(c){
			bool ans=query(a, b);
			printf("%s\n", ans?"YES":"NO");
			if(ans)
				update(a);
			else
				update(b);
		}
		else
			printf("%s\n", query(a, b)?"YES":"NO");
	}
	return 0;
}

