#include "bits/stdc++.h"
using namespace std;
vector<int> Map[100001];
pair<int, int> ans[100001];
int input[10];
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		for (int i = 0; i < 100001; i++)
			Map[i].clear();
		int N;
		scanf("%d", &N);
		int x, y;
		int max_x = -1;
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &x, &y);
			Map[x].push_back(y);
			max_x = max(max_x, x);
		}
        int idx = 1;
		int finish = 0;
		for (int i = 0; i <= max_x; i++) {
			int len = Map[i].size();
			if (len == 0)
				continue;
            sort(Map[i].begin(),Map[i].end());
			if (finish == Map[i][0]) {
				for (int j = 0; j < Map[i].size(); j++)
					ans[idx++] = make_pair(i, Map[i][j]);
				finish = Map[i][len - 1];
			}
			else if(finish == Map[i][len-1]) {
				for (int j = 0; j < Map[i].size(); j++)
					ans[idx++] = make_pair(i, Map[i][len - 1 - j]);
				finish = Map[i][0];
			}
		}
		int M;
		scanf("%d", &M);
		for (int i = 0; i < M; i++)
			scanf("%d", &input[i]);
		for (int i = 0; i < M; i++) {
			printf("%d %d\n", ans[input[i]].first,ans[input[i]].second);
		}
	}
	return 0;
}