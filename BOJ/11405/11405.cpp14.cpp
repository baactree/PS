#include <iostream>
#include <stdio.h>
#include <functional>
#include <queue>
#include <limits>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>

using namespace std;
#define INF 987654321
//0=s  /  1-100 p  /  101-200 b  / 201 t
int capacity[202][202];
int flow[202][202];
int parent[202];
int cost[202][202];
int dist[202];
int N, M;
int main() {
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &capacity[0][i]);
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", &capacity[N + i][N + M + 1]);
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &cost[j][N + i]);
			capacity[j][N + i] = INF;
		}
	}



	int source = 0;
	int sink = N + M + 1;
	int totalFlow = 0;
	int totalCost = 0;
	int V = N + M + 2;

	while (true) {
		fill(dist, dist + V, INF);
		memset(parent, -1, sizeof(parent));

		parent[source] = source;
		dist[source] = 0;
        //최단경로 탐색
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int now=q.front();
            q.pop();
            for(int there=0;there<V;there++){
                int there_cost;
                if(flow[there][now]>0)
                    there_cost=dist[now]-cost[there][now];
                else if(capacity[now][there]>flow[now][there])
                    there_cost=dist[now]+cost[now][there];
                else
                    continue;
                if(dist[there]>there_cost){
                    dist[there]=there_cost;
                    parent[there]=now;
                    q.push(there);
                }
            }
        }
		//이어서 계산
		if (dist[sink] == INF)
			break;
		int amount = INF;
		for (int p = sink; p != source; p = parent[p])
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);


			int here = sink;
			while (here != source) {
				int there = parent[here];
				flow[there][here]+=amount;
				flow[here][there] -= amount;
				here = there;
			}
			totalFlow++;
			totalCost += dist[sink]*amount;
	}
	printf("%d\n", totalCost);

	return 0;
}