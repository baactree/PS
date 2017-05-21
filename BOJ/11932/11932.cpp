// =====================================================================================
// 
//       Filename:  11932.cpp
//        Created:  2017년 05월 21일 19시 47분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Node{
	int c;
	Node *left, *right;
	Node(){}
	Node(int c, Node *left, Node *right):c(c), left(left), right(right){}
	Node* update(int le, int ri, int idx);
};
Node *root[100005];
Node *null;
Node* Node::update(int le, int ri, int idx){
	if(idx<le||ri<idx)
		return this;
	if(le==ri)
		return new Node(this->c+1, null, null);
	int mid=(le+ri)/2;
	return new Node(this->c+1, this->left->update(le, mid, idx), this->right->update(mid+1, ri, idx));
}

int n, m;
int p[100005][17];
int depth[100005];
vector<int> adj[100005];
int w[100005];
vector<int> arr;
void dfs(int now, int par, int dep){
	depth[now]=dep;
	root[now]=root[par]->update(0, arr.size()-1, w[now]);
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		p[there][0]=now;
		for(int i=1;i<17;i++)
			p[there][i]=p[p[there][i-1]][i-1];
		dfs(there, now, dep+1);
	}
}
int lca(int u, int v){
	if(depth[u]<depth[v])
		swap(u, v);
	for(int i=16;i>=0;i--)
		if(depth[u]-depth[v]>=(1<<i))
			u=p[u][i];
	if(u==v)
		return u;
	for(int i=16;i>=0;i--)
		if(p[u][i]!=p[v][i]){
			u=p[u][i];
			v=p[v][i];
		}
	return p[u][0];
}
int query(Node *a, Node *b, Node *c, Node *d, int le, int ri, int k){
	if(le==ri)
		return le;
	int cnt=a->left->c+b->left->c-c->left->c-d->left->c;
	int mid=(le+ri)/2;
	if(k<=cnt)
		return query(a->left, b->left, c->left, d->left, le, mid, k);
	return query(a->right, b->right, c->right, d->right, mid+1, ri, k-cnt);
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &w[i]);
		arr.push_back(w[i]);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for(int i=1;i<=n;i++)
		w[i]=(lower_bound(arr.begin(), arr.end(), w[i])-arr.begin());
	for(int i=0;i<n-1;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	null=new Node(0, NULL, NULL);
	null->right=null->left=null;
	root[0]=null;
	dfs(1, 0, 0);
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int l=lca(a, b);
		int ans=query(root[a], root[b], root[l], root[p[l][0]], 0, arr.size()-1, c);
		printf("%d\n", arr[ans]);
	}
	return 0;
}

