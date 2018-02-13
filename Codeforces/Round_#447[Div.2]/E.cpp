#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<pair<int,int> > adj[1000005];
vector<pair<int,int> > sadj[1000005];
vector<int> scc[1000005];
int sn,vn;
int s[1000005],d[1000005];
ll v[1000005];
stack<int> st;
ll cache[1000005];
ll t[20005];
int dfs(int now){
	int ret=d[now]=vn++;
	st.push(now);
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		if(d[there]==-1)
			ret=min(ret,dfs(there));
		else if(s[there]==-1)
			ret=min(ret,d[there]);
	}
	if(ret==d[now]){
		while(true){
			int temp=st.top();
			st.pop();
			s[temp]=sn;
			scc[sn].push_back(temp);
			if(temp==now)
				break;
		}
		sn++;
	}
	return ret;
}
ll calc(int x){
	ll le,ri,mid,ans;
	le=0;
	ri=2e4;
	ans=0;
	while(le<=ri){
		mid=(le+ri)/2;
		if(mid*(mid+1)<=x*2){
			ans=mid;
			le=mid+1;
		}
		else
			ri=mid-1;
	}
	return x*(ans+1)-t[ans];
}
ll solve(int now){
	ll &ret=cache[now];
	if(ret!=-1)
		return ret;
	ret=v[now];
	for(int i=0;i<sadj[now].size();i++){
		int there=sadj[now][i].first;
		int weight=sadj[now][i].second;
		ret=max(ret,solve(there)+weight+v[now]);
	}
	return ret;
}
int main(){
	for(ll i=1;i<20005;i++)
		t[i]=t[i-1]+(i*(i+1))/2;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		adj[a].push_back({b,d});
	}
	int st;
	scanf("%d",&st);
	memset(s,-1,sizeof(s));
	memset(d,-1,sizeof(d));
	for(int i=1;i<=n;i++)
		if(d[i]==-1)
			dfs(i);
	for(int now=1;now<=n;now++){
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			int weight=adj[now][i].second;
			if(s[now]!=s[there])
				sadj[s[now]].push_back({s[there],weight});
			else
				v[s[now]]+=calc(weight);
		}
	}
	memset(cache,-1,sizeof(cache));
	printf("%lld\n",solve(s[st]));
	return 0;
}