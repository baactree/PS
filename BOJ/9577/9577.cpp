// =====================================================================================
// 
//       Filename:  9577.cpp
//        Created:  2017년 06월 12일 15시 32분 25초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[105];
int matched[105];
bool trip[105];
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
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		for(int i=0;i<105;i++)
			adj[i].clear();
		scanf("%d%d", &n, &m);
		for(int i=0;i<m;i++){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			vector<int> vec;
			while(c--){
				int in;
				scanf("%d", &in);
				vec.push_back(in);
			}
			for(int j=a;j<b;j++){
				for(int k=0;k<vec.size();k++)
					adj[j].push_back(vec[k]);
			}
		}
		memset(matched, -1, sizeof(matched));
		int ans=-1;
		int flow=0;
		for(int i=0;i<105;i++){
			memset(trip, 0, sizeof(trip));
			if(dfs(i)){
				flow++;
				if(flow==n){
					ans=i+1;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

