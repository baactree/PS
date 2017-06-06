// =====================================================================================
// 
//       Filename:  1219.cpp
//        Created:  2017년 06월 06일 14시 40분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, st, fi;
vector<pair<int, int> > adj[100];
ll dist[100];
const ll linf = 0x3f3f3f3f3f3f3f3f;
bool possi[100][100];
ll arr[100];
int main(){
	scanf("%d%d%d%d", &n, &st, &fi, &m);
	for(int i=0;i<m;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d});
		possi[a][b]=1;
	}
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		arr[i]=in;
		possi[i][i]=1;
	}
	memset(dist, 0x3f, sizeof(dist));
	dist[st]=-arr[st];;
	int v=n;
	for(int k=0;k<v;k++)
		for(int i=0;i<v;i++)
			for(int j=0;j<v;j++)
				possi[i][j]|=possi[i][k]&&possi[k][j];
	bool update=false;
	bool fiupdate=false;
	for(int k=0;k<v;k++){
		update=false;
		for(int now=0;now<v;now++){
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i].first;
				ll there_cost=adj[now][i].second+dist[now]-arr[there];
				if(dist[now]!=linf&&dist[there]>there_cost){
					dist[there]=there_cost;
					update=true;
					if(k==v-1&&possi[there][fi])
						fiupdate=true;
				}
			}
		}
		if(!update)
			break;
	}
	if(update&&fiupdate){
		printf("Gee\n");
	}
	else if(dist[fi]>=linf-1e12){
		printf("gg\n");
	}
	else
		printf("%lld\n", -dist[fi]);
	return 0;
}

