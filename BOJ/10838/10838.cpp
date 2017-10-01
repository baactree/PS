#include <bits/stdc++.h>
using namespace std;
int n,k;
int par[100005],col[100005];
int cnt[100005];
void paint(int u,int v,int l,int c){
	while(u!=l){
		col[u]=c;
		u=par[u];
	}
	while(v!=l){
		col[v]=c;
		v=par[v];
	}
}
int calc(int u,int v,int l){
	set<int> s;
	int ret=0;
	while(u!=l){
		if(!cnt[col[u]])
			ret++;
		s.insert(col[u]);
		u=par[u];
	}
	while(v!=l){
		if(!cnt[col[v]])
			ret++;
		s.insert(col[v]);
		v=par[v];
	}
	return s.size();
}
int lca(int u,int v){
	vector<int> vec;
	int p=1005;
	while(u!=-1&&p--){
		vec.push_back(u);
		cnt[u]++;
		u=par[u];
	}
	int ret=-1;
	while(v!=-1){
		if(cnt[v]){
			ret=v;
			break;
		}
		v=par[v];
	}
	for(int i=0;i<vec.size();i++)
		cnt[vec[i]]=0;
	return ret;
}
int main(){
	scanf("%d%d",&n,&k);
	par[0]=-1;
	while(k--){
		int type;
		scanf("%d",&type);
		if(type==1){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			int l=lca(a,b);
			paint(a,b,l,c);
		}
		else if(type==2){
			int a,b;
			scanf("%d%d",&a,&b);
			par[a]=b;
		}
		else{
			int a,b;
			scanf("%d%d",&a,&b);
			int l=lca(a,b);
			printf("%d\n",calc(a,b,l));
		}
	}
	return 0;
}