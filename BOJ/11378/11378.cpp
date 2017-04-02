// =====================================================================================
// 
//       Filename:  11378.cpp
//        Created:  2017년 04월 02일 13시 56분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> adj[1005];
bool used[1005];
int matched[1005];
bool trip[1005];
bool dfs(int v){
	if(trip[v])
		return false;
	trip[v]=true;
	for(int i=0;i<adj[v].size();i++){
		int there=adj[v][i];
		if(matched[there]==-1||dfs(matched[there])){
			matched[there]=v;
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=n;i++){
		int cnt;
		scanf("%d", &cnt);
		for(int j=0;j<cnt;j++){
			int in;
			scanf("%d", &in);
			adj[i].push_back(in);
			used[in]=true;
		}
	}
	for(int i=1;i<=m;i++)
		if(used[i])
			adj[n+1].push_back(i);
	memset(matched, -1, sizeof(matched));
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(trip, 0, sizeof(trip));
		if(dfs(i))
			ans++;
	}
	for(int i=0;i<k;i++){
		memset(trip, 0, sizeof(trip));
		if(dfs(n+1))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

