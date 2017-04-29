// =====================================================================================
// 
//       Filename:  1647.cpp
//        Created:  2017년 04월 29일 13시 41분 04초
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
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
void merge(int x, int y){
	x=find(x);
	y=find(y);
	par[y]=x;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		edge.push_back({d, {a, b}});	
	}
	for(int i=1;i<=n;i++)
		par[i]=i;
	sort(edge.begin(), edge.end());
	int cnt=0;
	long long ans=0;
	for(int i=0;i<edge.size();i++){
		if(cnt==n-2)
			break;
		int u=edge[i].second.first;
		int v=edge[i].second.second;
		int w=edge[i].first;
		if(find(u)!=find(v)){
			cnt++;
			merge(u, v);
			ans+=w;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

