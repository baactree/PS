// =====================================================================================
// 
//       Filename:  5214.cpp
//        Created:  2017년 04월 07일 16시 17분 52초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[110001];
int n, m, k;
int dist[110001];
int main(){
	scanf("%d%d%d", &n, &k, &m);
	for(int i=1;i<=m;i++){
		for(int j=0;j<k;j++){
			int in;
			scanf("%d", &in);
			adj[n+i].push_back(in);
			adj[in].push_back(n+i);
		}
	}
	memset(dist, -1, sizeof(dist));
	dist[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i];
			if(dist[there]==-1){
				dist[there]=dist[now]+1;
				q.push(there);
			}
		}
	}
	printf("%d\n", dist[n]==-1?-1:dist[n]/2+1);
	return 0;
}

