// =====================================================================================
// 
//       Filename:  2463.cpp
//        Created:  2017년 05월 16일 20시 14분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, pair<int, int> > > edge;
int par[100005];
int cnt[100005];
const int mod=1e9;
int find(int x){
	if(x==par[x])
		return x;
	return par[x]=find(par[x]);
}
void merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return ;
	cnt[y]+=cnt[x];
	par[x]=y;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		par[i]=i;
		cnt[i]=1;
	}
	int es=0;
	for(int i=0;i<m;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		edge.push_back({d, {a, b}});
		es=(es+d)%mod;
	}
	sort(edge.begin(), edge.end());
	int ans=0;
	int sum=0;
	for(int i=m-1;i>=0;i--){
		int u, v, c;
		u=edge[i].second.first;
		v=edge[i].second.second;
		c=edge[i].first;
		u=find(u);
		v=find(v);
		if(u==v){
			sum=(sum+c)%mod;
			continue;
		}
		ans=(ans+((((long long)cnt[u]*cnt[v])%mod)*((es-sum+mod)%mod))%mod)%mod;
		sum=(sum+c)%mod;
		merge(u, v);
	}
	printf("%d\n", ans);
	return 0;
}

