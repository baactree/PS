#include <bits/stdc++.h>
using namespace std;
struct Query{
	int x,y;
};
struct State{
	int le,ri;
	vector<int> arr;
};
int n,m,q;
vector<pair<int,int> > edge[1000005];
Query query[100005];
pair<int,int> ans[100005];
int par[100005];
int cnt[100005];
int fi;
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	par[x]=y;
	cnt[y]+=cnt[x];
}
void possi(int x,const vector<int> &arr,vector<int> &le,vector<int> &ri){
	while(fi<x){
		fi++;
		for(int i=0;i<edge[fi].size();i++){
			int u=edge[fi][i].first;
			int v=edge[fi][i].second;
			merge(u,v);
		}
	}
	for(int i=0;i<arr.size();i++){
		int u=query[arr[i]].x;
		int v=query[arr[i]].y;
		if(find(u)==find(v)){
			le.push_back(arr[i]);
			ans[arr[i]].first=x;
			ans[arr[i]].second=cnt[find(u)];
		}
		else
			ri.push_back(arr[i]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edge[c].push_back({a,b});
	}
	scanf("%d",&q);
	vector<int> vec;
	for(int i=0;i<q;i++){
		scanf("%d%d",&query[i].x,&query[i].y);
		vec.push_back(i);
	}
	queue<State> qu;
	qu.push({1,1000000,vec});
	while(!qu.empty()){
		for(int i=1;i<=n;i++){
			par[i]=i;
			cnt[i]=1;
		}
		fi=-1;
		int sz=qu.size();
		while(sz--){
			int le=qu.front().le;
			int ri=qu.front().ri;
			vector<int> now=qu.front().arr;
			qu.pop();
			if(le>ri)
				continue;
			int mid=(le+ri)/2;
			vector<int> lv,rv;
			possi(mid,now,lv,rv);
			qu.push({le,mid-1,lv});
			qu.push({mid+1,ri,rv});
		}
	}
	for(int i=0;i<q;i++){
		if(!ans[i].first)
			printf("-1\n");
		else
			printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}