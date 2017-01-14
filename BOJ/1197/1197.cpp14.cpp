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


vector<pair<int, int> >Map[10001];
bool trip[10001];
int search(int v) {
	priority_queue<pair<int, int> > q;
	q.push(make_pair(-987654321, v));
	int sum = 0;
	while (!q.empty()) {
		int x = q.top().second;
		if (trip[x]) {
			q.pop();
			continue;
		}
		trip[x] = true;
		if (q.top().first != -987654321)
			sum += -q.top().first;
		q.pop();
		int _size = Map[x].size();
		for (int i = 0; i < _size; i++) {
			if (!trip[Map[x][i].first]) {
				q.push(make_pair(-Map[x][i].second, Map[x][i].first));
			}
		}
	}
	return sum;
}
int main() {
	int N, M;
	int a, b, d;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &d);
		Map[a].push_back(make_pair(b, d));
		Map[b].push_back(make_pair(a, d));
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (!trip[i]) {
			ans += search(i);
		}
	}
	printf("%d\n", ans);
	return 0;
}