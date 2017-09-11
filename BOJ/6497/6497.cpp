// =====================================================================================
// 
//       Filename:  6497.cpp
//        Created:  2017년 09월 11일 22시 21분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, pair<int, int> > > edge;
int par[200005];
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
typedef long long ll;
int main(){
	while(true){
		scanf("%d%d", &n, &m);
		if(n==0&&m==0)
			break;
		ll sum=0;
		edge.clear();
		for(int i=0;i<m;i++){
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			edge.push_back({d, {a, b}});
			sum+=d;
		}
		for(int i=0;i<n;i++)
			par[i]=i;
		sort(edge.begin(), edge.end());
		ll p=0;
		for(int i=0;i<m;i++){
			int u=edge[i].second.first;
			int v=edge[i].second.second;
			int w=edge[i].first;
			u=find(u);
			v=find(v);
			if(u==v)
				continue;
			p+=w;
			par[u]=v;
		}
		printf("%lld\n", sum-p);
	}
	return 0;
}

