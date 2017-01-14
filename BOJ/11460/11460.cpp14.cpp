#include "bits/stdc++.h"
using namespace std;
vector<int> le[1000000];
vector<int> ri[1000000];
bool trip[1000000];
int arr[1000000];
int N;
queue<int> q;
int main() {
	while (true) {
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int i = 0; i < N; i++) {
			ri[i].clear();
			le[i].clear();
			trip[i] = false;
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			if (i + arr[i] < N)
				ri[i + arr[i]].push_back(i);
			if (i - arr[i] >= 0)
				le[i - arr[i]].push_back(i);
		}
		trip[0] = true;
		q.push(0);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			int now_right = now + arr[now];
			int now_left = now - arr[now];
			if (now_right < N) {
				for (int i = 0; i < le[now_right].size(); i++) {
					int there = le[now_right][i];
					if (!trip[there]) {
						trip[there] = true;
						q.push(there);
					}
				}
			}
			if (now_left >= 0) {
				for (int i = 0; i < ri[now_left].size(); i++) {
					int there = ri[now_left][i];
					if (!trip[there]) {
						trip[there] = true;
						q.push(there);
					}
				}
			}
		}
		for (int i = N - 1; i >= 0; i--)
			if (trip[i]) {
				printf("%d\n", i);
				break;
			}
	}
}