// =====================================================================================
// 
//       Filename:  2623.cpp
//        Created:  2017년 02월 25일 19시 07분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001];
int cnt[1001];
int trip[1001];
bool fi[1001];
int counter=0;
bool dfs(int v){
	trip[v]=counter++;
	bool ret=false;
	for(int i=0;i<adj[v].size();i++){
		int there=adj[v][i];
		if(trip[there]==-1)
			ret|=dfs(there);
		else if(trip[v]>=trip[there]&&fi[there]==0)
			return true;
	}
	fi[v]=true;
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int in;
		scanf("%d", &in);
		int bef;
		scanf("%d", &bef);
		for(int j=1;j<in;j++){
			int to;
			scanf("%d", &to);
			adj[bef].push_back(to);
			cnt[to]++;
			bef=to;
		}
	}
	memset(trip, -1, sizeof(trip));
	for(int i=1;i<=n;i++){
		if(trip[i]==-1){
			bool flag=dfs(i);
			if(flag){
				printf("0\n");
				return 0;
			}
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(cnt[i]==0)
			q.push(i);
	vector<int> ans;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		ans.push_back(now);
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i];
			cnt[there]--;
			if(cnt[there]==0)
				q.push(there);
		}
	}
	for(int i=0;i<ans.size();i++)
		printf("%d\n", ans[i]);
	return 0;
}

