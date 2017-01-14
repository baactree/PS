#include "bits/stdc++.h"
using namespace std;
int Map[1001];
bool trip[1001];
int N;
bool dfs(int v) {
	if (trip[v])
		return true;
	trip[v] = true;
	bool ret = false;
	if (Map[v] != 0 && dfs(Map[v]))
		return true;
	return false;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(trip, 0, sizeof(trip));
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d", &Map[i]);
		int ans = 0;
		for (int i = 1; i <= N; i++)
			if (!trip[i])
				if (dfs(i))
					ans++;
		printf("%d\n", ans);
	}
	return 0;
}