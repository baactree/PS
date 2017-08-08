// =====================================================================================
// 
//       Filename:  1057.cpp
//        Created:  2017년 08월 08일 18시 28분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[105][105];
vector<pair<int, int> > adj[105];
int dist[105];
const int inf=0x3f3f3f3f;
int main(){
	int tc=0;
	while(scanf("%d%d", &n, &m)!=EOF){
		if(n==0&&m==0)
			break;
		memset(mat, 0x3f, sizeof(mat));
		for(int i=0;i<105;i++)
			adj[i].clear();
		for(int i=0;i<m;i++){
			int a, b;
			scanf("%d%d", &a, &b);
			mat[a][b]=1;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||mat[i][j]==inf||mat[j][i]==inf)
					continue;
				adj[i].push_back({j, mat[i][j]+mat[j][i]-1});
			}
		}
		for(int i=1;i<=n;i++){
			cout<<"now : "<<i<<endl;
			for(int j=0;j<adj[i].size();j++)
				printf("%d %d / ", adj[i][j].first, adj[i][j].second);
			printf("\n");
		}
		memset(dist, 0x3f,  sizeof(dist));
		dist[1]=0;
		priority_queue<pair<int, int> > pq;
		pq.push({0, 1});
		while(!pq.empty()){
			int now=pq.top().second;
			int cost=-pq.top().first;
			pq.pop();
			if(dist[now]<cost)
				continue;
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i].first;
				int there_cost=adj[now][i].second+cost;
				if(there_cost<dist[there]){
					dist[there]=there_cost;
					pq.push({-there_cost, there});
				}
			}
		}
		tc++;
		printf("Network %d\n", tc);
		if(dist[2]==inf)
			printf("IMPOSSIBLE\n");
		else
			printf("Minimum number of nodes = %d\n", dist[2]+1);
		printf("\n");
	}
	return 0;
}

