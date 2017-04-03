// =====================================================================================
// 
//       Filename:  13325.cpp
//        Created:  2017년 04월 03일 10시 22분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k;
vector<pair<int, int> > adj[1<<(20+1)+1];
int dfs(int now){
	int ret=0;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int cost=adj[now][i].second;
		ret=max(ret, cost+dfs(there));
	}
	return ret;
}
int dfs2(int now, int dist){
	int ret=0;
	vector<int> temp;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int cost=adj[now][i].second;
		temp.push_back(dfs2(there, dist-cost));
	}
	if(!temp.empty())
		ret=*min_element(temp.begin(), temp.end());
	else
		return dist;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int &cost=adj[now][i].second;
		cost+=temp[i]-ret;
	}
	return ret;
}
int main(){
	scanf("%d", &k);
	for(int i=1;i<1<<k;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[i].push_back({i*2, a});
		adj[i].push_back({i*2+1, b});
	}
	int max_dist=dfs(1);
	dfs2(1, max_dist);
	int ans=0;
	for(int i=1;i<1<<k;i++){
		for(int j=0;j<adj[i].size();j++){
			ans+=adj[i][j].second;
		}
	}
	printf("%d\n", ans);
	return 0;
}

