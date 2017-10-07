#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<pair<int,pair<int,int> > > adj[15];
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
ll dfs(int now,int par){
	ll ret=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int p=adj[now][i].second.first;
		if(there==par)
			continue;
		ll temp=dfs(there,now);
		ret*=temp*p;
	}
	return ret;
}
void dfs2(int now,int par,ll x,vector<ll> &vec){
	vec[now]=x;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int p=adj[now][i].second.first;
		int q=adj[now][i].second.second;
		if(there==par)
			continue;
		dfs2(there,now,x/p*q,vec);
	}
}
int main(){
	scanf("%d",&n);
	if(n==1)
		return !printf("1\n");
	for(int i=0;i<n-1;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		adj[a].push_back({b,{c,d}});
		adj[b].push_back({a,{d,c}});
	}
	ll min_value=0x3f3f3f3f3f3f3f3f;
	vector<ll> ans;
	for(int i=0;i<n;i++){
		vector<ll> vec(n);
		ll p=dfs(i,-1);
		dfs2(i,-1,p,vec);
		ll g=gcd(vec[0],vec[1]);
		for(int j=2;j<vec.size();j++)
			g=gcd(g,vec[j]);
		ll sum=0;
		for(int j=0;j<vec.size();j++){
			vec[j]/=g;
			sum+=vec[j];
			sum=min(sum,0x3f3f3f3f3f3f3f3fll);
		}
		if(sum<min_value){
			min_value=sum;
			ans=vec;
		}
	}
	for(auto x:ans)
		printf("%lld ", x);
	printf("\n");
	return 0;
}