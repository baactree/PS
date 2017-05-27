// =====================================================================================
// 
//       Filename:  13418.cpp
//        Created:  2017년 05월 27일 15시 27분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, pair<int, int> > > edge;
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
	for(int i=0;i<m+1;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edge.push_back({1-c, {a, b}});
	}
	sort(edge.begin(), edge.end());
	for(int i=0;i<=n;i++)
		par[i]=i;
	int minv=0;
	for(int i=0;i<m+1;i++){
		int u=edge[i].second.first;
		int v=edge[i].second.second;
		int w=edge[i].first;
		if(find(u)==find(v))
			continue;
		minv+=w;
		merge(u, v);
	}
	int maxv=0;
	reverse(edge.begin(), edge.end());
	for(int i=0;i<=n;i++)
		par[i]=i;
	for(int i=0;i<m+1;i++){
		int u=edge[i].second.first;
		int v=edge[i].second.second;
		int w=edge[i].first;
		if(find(u)==find(v))
			continue;
		maxv+=w;
		merge(u, v);
	}
	printf("%d\n", maxv*maxv-minv*minv);
	return 0;
}

