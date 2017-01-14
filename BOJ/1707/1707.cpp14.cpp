#include "bits/stdc++.h"
using namespace std;
vector<int> Map[20001];
int trip[20001];
int N, M;
bool flag;
void search(int v,int type) {
	if (trip[v] != 0) {
		if (trip[v] != type)
			flag = false;
		return;
	}
	trip[v] = type;
	for (int i = 0; i < Map[v].size(); i++)
		search(Map[v][i], -type);
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(trip, 0, sizeof(trip));
		scanf("%d%d", &N, &M);
		int a, b;
		for (int i = 1; i <= N; i++)
			Map[i].clear();
		for (int i = 0; i < M; i++) {
			scanf("%d%d", &a, &b);
			Map[a].push_back(b);
			Map[b].push_back(a);
		}
		flag = true;
		for (int i = 1; i <= N; i++)
			if (trip[i] == 0)
				search(i, 1);
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}