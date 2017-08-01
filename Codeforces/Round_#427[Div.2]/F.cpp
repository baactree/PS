// =====================================================================================
// 
//       Filename:  F.cpp
//        Created:  2017년 08월 01일 20시 53분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<pair<int, int> > adj[200005];
int d[200005], s[200005];
ll w[200005], dep[200005], pred[200005], sufd[200005], pref[200005], suff[200005];
vector<int> cycle;
int vn, sn, cn;
stack<int> st;
int dfs(int now, int par){
	int ret=d[now]=vn++;
	st.push(now);
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		if(there==par)
			continue;
		if(d[there]==-1)
			ret=min(ret, dfs(there, now));
		else if(s[there]==-1)
			ret=min(ret, d[there]);
	}
	if(ret==d[now]){
		vector<int> vec;
		while(true){
			int temp=st.top();
			st.pop();
			s[temp]=sn;
			vec.push_back(temp);
			if(temp==now)
				break;
		}
		sn++;
		if(vec.size()>1)
			cycle=vec;
	}
	return ret;
}
void dfs2(int now, int next, int idx){
	if(d[now]!=1)
		return;
	d[now]=0;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int weight=adj[now][i].second;
		if(there==next){
			w[idx]=weight;
			dfs2(there, cycle[(idx+2)%cn], idx+1);
			return;
		}
	}
}
int u, v;
pair<ll, int> dfs3(int now, int par){
	d[now]=1;
	pair<ll, int> ret={0, now};
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int weight=adj[now][i].second;
		if(there==par||d[there]!=-1)
			continue;
		if((now==u&&there==v)||(now==v&&there==u))
			continue;
		auto temp=dfs3(there, now);
		temp.first+=weight;
		ret=max(ret, temp);
	}
	return ret;
}
const ll inf=0x3f3f3f3f3f3f3f3f;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	memset(d, -1, sizeof(d));
	memset(s, -1, sizeof(s));
	for(int i=1;i<=n;i++)
		if(d[i]==-1)
			dfs(i, 0);
	cn=cycle.size();
	memset(d, -1, sizeof(d));
	for(int i=0;i<cn;i++)
		d[cycle[i]]=1;
	dfs2(cycle[0], cycle[1], 0);	
	for(int i=0;i<cn;i++)
		dep[i]=dfs3(cycle[i], 0).first;
	ll cf=-inf;
	ll cl=0;
	for(int i=0;i<cn;i++){
		if(i==0){
			pred[i]=dep[i];
			pref[i]=dep[i];
		}
		else{
			cl+=w[i-1];
			cf=max(cf, dep[i-1])+w[i-1];
			pred[i]=max(pred[i-1], cf+dep[i]);
			pref[i]=max(pref[i-1], cl+dep[i]);
		}
	}
	cl=0;
	cf=-inf;
	sufd[cn]=-inf;
	suff[cn]=-inf;
	for(int i=cn-1;i>0;i--){
		cl+=w[i];
		cf=max(cf, dep[i+1])+w[i];
		sufd[i]=max(sufd[i+1], cf+dep[i]);
		suff[i]=max(suff[i+1], cl+dep[i]);
	}
	ll min_value=inf;
	int min_idx=-1;
	for(int i=0;i<cn;i++){
		ll now=max({pref[i]+suff[i+1], pred[i], sufd[i+1]});
		if(now<min_value){
			min_value=now;
			min_idx=i;
		}
	}
	u=cycle[min_idx];
	v=cycle[(min_idx+1)%cn];
	memset(d, -1, sizeof(d));
	int root=dfs3(1, 0).second;
	memset(d, -1, sizeof(d));
	ll ans=dfs3(root, 0).first;
	printf("%lld\n", ans);
	return 0;
}

