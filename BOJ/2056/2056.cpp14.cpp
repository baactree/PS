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

vector<int>Map[10001];
queue<int> q;
int _time[10001];
int par[10001];
int sum_time[10001];
int main() {
	int N;
	int W, T;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &W, &T);
		_time[i] = W;
		int V;
		for (int j = 0; j < T; j++) {
			scanf("%d", &V);
			Map[V].push_back(i);
			par[i]++;
		}
	}
	

	for (int i = 1; i <= N; i++) {
		if (!par[i]) {
			q.push(i);
			sum_time[i] = _time[i];
		}
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		int _size = Map[v].size();
		for (int i = 0; i < _size; i++) {
			par[Map[v][i]]--;
			sum_time[Map[v][i]] = max(sum_time[Map[v][i]], sum_time[v]+_time[Map[v][i]]);
			if (!par[Map[v][i]]) {
				q.push(Map[v][i]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, sum_time[i]);
	}

	printf("%d\n", ans);
	return 0;
}




