#include "bits/stdc++.h"
using namespace std;
struct enemy {
	int x, y, r;
};
enemy emy[3000];
vector<int> Map[3000];
bool trip[3000];
bool cmp(const enemy&a, const enemy&b) {
	int x = a.x - b.x;
	int y = a.y - b.y;
	return (x*x + y*y) <= ((a.r + b.r)*(a.r + b.r));
}
void dfs(int now) {
	trip[now] = true;
	for (int i = 0; i < Map[now].size(); i++) {
		int there = Map[now][i];
		if (!trip[there])
			dfs(there);
	}
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			scanf("%d%d%d", &emy[i].x, &emy[i].y, &emy[i].r);
			Map[i].clear();
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (i == j)continue;
				if (cmp(emy[i], emy[j])) {
					Map[i].push_back(j);
					Map[j].push_back(i);
				}
			}
		int cnt = 0;
		memset(trip, 0, sizeof(trip));
		for (int i = 0; i < N; i++)
			if (!trip[i]) {
				cnt++;
				dfs(i);
			}
		printf("%d\n", cnt);
	}
	return 0;
}