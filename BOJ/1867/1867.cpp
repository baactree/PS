// =====================================================================================
// 
//       Filename:  1867.cpp
//        Created:  2017년 03월 27일 22시 52분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> adj[501];
int matched[501];
int trip[501];
bool dfs(int x){
	if(trip[x])
		return false;
	trip[x]=true;
	for(int i=0;i<adj[x].size();i++){
		int there=adj[x][i];
		if(matched[there]==-1||dfs(matched[there])){
			matched[there]=x;
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<k;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}
	int ans=0;
	memset(matched, -1, sizeof(matched));
	for(int i=1;i<=n;i++){
		memset(trip, 0, sizeof(trip));
		ans+=dfs(i);
	}
	printf("%d\n", ans);
	return 0;
}

