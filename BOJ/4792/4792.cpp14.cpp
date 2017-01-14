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

vector<pair<int, int> >Map[1001];
int N, M, K;
int trip[1001];
int search(int v) {
	int ret = 0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, v));
	while (!q.empty()) {
		int x = q.top().second;
		if (trip[x]) {
			q.pop();
			continue;
		}
		ret += -q.top().first;
		q.pop();
		trip[x] = true;
		int _size = Map[x].size();
		for (int i = 0; i < _size; i++) {
			int y = Map[x][i].second;
			if (!trip[y]) {
				q.push(make_pair(-Map[x][i].first,y));
			}
		}
	}
	return ret;
}
int main() {
	while (true) {
		cin >> N >> M >> K;
		if (N == 0 && M == 0 && K == 0)
			break;
		memset(trip, 0, sizeof(trip));
		for (int i = 1; i <= N; i++)
			Map[i].clear();
		char c[2];
		int a, b;
		for (int i = 0; i < M; i++) {
			scanf("%s%d%d", c, &a, &b);
			if (c[0] == 'R') {
				Map[a].push_back(make_pair(0, b));
				Map[b].push_back(make_pair(0, a));
			}
			else {
				Map[a].push_back(make_pair(1, b));
				Map[b].push_back(make_pair(1, a));
			}
		}
		int min = search(1);
		int len;
		for (int i = 1; i <= N; i++) {
			len = Map[i].size();
			for (int j = 0; j < len; j++) {
				if (Map[i][j].first == 1)
					Map[i][j].first = -1;
			}
		}
		memset(trip, 0, sizeof(trip));
		int max = -search(1);
		if (K >= min&&K <= max)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}