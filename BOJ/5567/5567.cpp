// =====================================================================================
// 
//       Filename:  5567.cpp
//        Created:  2017년 03월 31일 17시 31분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[501];
int dist[501];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(dist, 0x3f, sizeof(dist));
	queue<int> q;
	dist[1]=0;
	q.push(1);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i];
			if(dist[there]>dist[now]+1){
				dist[there]=dist[now]+1;
				q.push(there);
			}
		}
	}
	int ans=0;
	for(int i=2;i<=n;i++)
		if(dist[i]<=2)
			ans++;
	printf("%d\n", ans);

	return 0;
}

