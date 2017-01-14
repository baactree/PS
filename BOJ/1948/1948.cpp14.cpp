#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <deque>
using namespace std;


vector<pair<int,int> >Map[10001];
vector<int> back_Map[10001];
priority_queue<int> q;
int par[10001];
int dist[10001];
bool trip[10001];
int search(int v) {
	if (trip[v])
		return 0;
	trip[v] = true;
	int ret = 0;
	int _size = back_Map[v].size();
	for (int i = 0; i < _size; i++) {
			ret += search(back_Map[v][i]) + 1;
	}
	return ret;
}
int main() {
	int N, M;
	int	a, b, d;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a,&b,&d);
		Map[a].push_back(make_pair(b,d));
		par[b]++;
	}

	int st, fi;
	cin >> st >> fi;
	//pair -가중치 -인덱스
	q.push(-st);
	while (!q.empty()) {
		int x = -q.top();
		q.pop();
		int _size = Map[x].size();
		for (int i = 0; i < _size; i++) {
			int y = Map[x][i].first;
			if (dist[y] < dist[x] + Map[x][i].second) {
				dist[y] = dist[x] + Map[x][i].second;
				back_Map[y].clear();
				back_Map[y].push_back(x);
			}
			else if (dist[y] == dist[x] + Map[x][i].second) {
				back_Map[y].push_back(x);
			}
			par[y]--;
			if (!par[y] && y != fi)
				q.push(-y);
		}
	}
	


	printf("%d\n%d\n", dist[fi], search(fi));

	return 0;
}




