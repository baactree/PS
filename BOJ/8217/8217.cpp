#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Query{
	int l,r,a;
};
struct State{
	int le,ri;
	vector<int> arr;
};
int n,m,k;
vector<int> a[300005];
int b[300005];
Query q[300005];
int ans[300005];
int fi;
ll tree[300005];
void update(int idx,int val){
	while(idx<300005){
		tree[idx]+=val;
		idx+=idx&(-idx);
	}
}
ll query(int idx){
	ll ret=0;
	while(idx){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
bool possi(int x,const vector<int> &now,vector<int> &le,vector<int> &ri){
	for(;fi<x;fi++){
		int l=q[fi+1].l;
		int r=q[fi+1].r;
		int a=q[fi+1].a;
		if(l<=r){
			update(l,a);
			update(r+1,-a);
		}
		else{
			update(1,a);
			update(r+1,-a);
			update(l,a);
			update(m+1,-a);
		}
	}
	for(int i=0;i<now.size();i++){
		ll sum=0;
		for(int j=0;j<a[now[i]].size();j++){
			int g=a[now[i]][j];
			sum+=query(g);
			sum=min(sum,0x3f3f3f3fll);
		}
		if(sum>=b[now[i]]){
			le.push_back(now[i]);
			ans[now[i]]=x;
		}
		else{
			ri.push_back(now[i]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		a[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].a);
	memset(ans,-1,sizeof(ans));
	vector<int> vec;
	for(int i=1;i<=n;i++)
		vec.push_back(i);
	queue<State> q;
	q.push({1,k,vec});
	while(!q.empty()){
		int sz=q.size();
		fi=0;
		memset(tree,0,sizeof(tree));
		while(sz--){
			int le=q.front().le;
			int ri=q.front().ri;
			vector<int> now=q.front().arr;
			q.pop();
			if(le>ri)
				continue;
			int mid=(le+ri)/2;
			vector<int> le_arr,ri_arr;
			possi(mid,now,le_arr,ri_arr);
			q.push({le,mid-1,le_arr});
			q.push({mid+1,ri,ri_arr});
		}	
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==-1)
			printf("NIE\n");
		else
			printf("%d\n",ans[i]);
	}
	return 0;
}