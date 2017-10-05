#include <bits/stdc++.h>
using namespace std;
int n,m,l;
vector<pair<int,int> > adj[100005];
bool trip[100005];
int par[100005],cost[100005];
typedef long long ll;
typedef pair<ll,ll> p;
p merge(p a,p b){
	if(a.second>a.first)
		swap(a.second,a.first);
	if(b.second>b.first)
		swap(b.second,b.first);
	if(b.first+l<a.second)
		return {a.first,a.second};
	if(a.first+l<b.second)
		return {b.first,b.second};
	if(a.first>b.first)
		return {a.first,b.first+l};
	return {a.first+l,b.first};
}
pair<ll,int> dfs(int now,int parent){
	trip[now]=true;
	pair<ll,int> ret(0ll,now);
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int weight=adj[now][i].second;
		if(there==parent)
			continue;
		par[there]=now;
		cost[there]=weight;
		auto temp=dfs(there,now);
		temp.first+=weight;
		ret=max(ret,temp);
	}
	return ret;
}
int main(){
	scanf("%d%d%d",&n,&m,&l);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	vector<p> vec;
	vector<ll> tt;
	for(int i=0;i<n;i++){
		if(!trip[i]){
			auto temp=dfs(i,-1);
			int root=temp.second;
			temp=dfs(root,-1);
			int now=temp.second;
			//cout<<root<<" "<<now<<endl;
			ll sum=0;
			ll g=0x3f3f3f3f3f3f3f3f;
			while(true){
				ll dist=max(sum,temp.first-sum);
				g=min(g,dist);
				if(now==root)
					break;
				sum+=cost[now];
				now=par[now];
			}
			vec.push_back({g,temp.first-g});
			//printf("%d %lld %lld\n",i,vec.back().first,vec.back().second);
		}
	}
	sort(vec.begin(),vec.end());
	while(vec.size()>1){
		auto a=vec.back();
		vec.pop_back();
		auto b=vec.back();
		vec.pop_back();
		vec.push_back(merge(a,b));
	}
	printf("%lld\n",vec[0].first+vec[0].second);
	return 0;
}