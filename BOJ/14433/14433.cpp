// =====================================================================================
// 
//       Filename:  14433.cpp
//        Created:  2017년 09월 16일 18시 54분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int k[2];
int cnt[2];
vector<int> adj[305];
bool trip[305];
int matched[305];
bool dfs(int now){
	if(trip[now])
		return false;
	trip[now]=true;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(matched[there]==-1||dfs(matched[there])){
			matched[there]=now;
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d%d", &n, &m);
	scanf("%d%d", &k[0], &k[1]);
	for(int i=0;i<2;i++){
		for(int j=0;j<305;j++)
			adj[j].clear();
		for(int j=0;j<k[i];j++){
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
		}
		memset(matched, -1, sizeof(matched));
		for(int j=1;j<=n;j++){
			memset(trip, 0, sizeof(trip));
			if(dfs(j))
				cnt[i]++;
		}
	}
	if(cnt[0]>=cnt[1])
		printf("그만 알아보자");
	else
		printf("네 다음 힐딱이");
	return 0;
}

