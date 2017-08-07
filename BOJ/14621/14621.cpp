// =====================================================================================
// 
//       Filename:  14621.cpp
//        Created:  2017년 08월 03일 01시 34분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > edge;
int n, m;
int mode[1005];
int par[1005];
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
void merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	par[x]=y;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		par[i]=i;
		char in[2];
		scanf("%s", in);
		mode[i]=(in[0]=='M');
	}
	for(int i=0;i<m;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		edge.push_back({d, {a, b}});
	}
	int cnt=0;
	int ans=0;
	sort(edge.begin(), edge.end());
	for(int i=0;i<edge.size();i++){
		int w=edge[i].first;
		int u=edge[i].second.first;
		int v=edge[i].second.second;
		if(mode[u]==mode[v])
			continue;
		if(find(u)==find(v))
			continue;
		merge(u, v);
		cnt++;
		ans+=w;
	}
	if(cnt!=n-1)
		return !printf("-1\n");
	printf("%d\n", ans);
	return 0;
}

