#include "bits/stdc++.h"
using namespace std;
int N;
vector<int> Map[100001];
bool trip[100001];
int dp[100001][16];
void search(int here) {
	trip[here] = true;
	for (int i = 0; i < 16; i++)
		dp[here][i] = i + 1;
	for (int i = 0; i < Map[here].size(); i++) {
		int there = Map[here][i];
		if (!trip[there]) {
			search(there);
			for(int i=0;i<16;i++){
				int min_val=0x3f3f3f3f;
				for(int j=0;j<16;j++){
					if(i==j)
						continue;
					min_val=min(min_val, dp[there][j]);
				}
				dp[here][i]+=min_val;
			}
		}
	}
}
int main() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &a, &b);
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	search(1);
	int ans = 1e9;
	for (int i = 0; i < 16; i++)
		ans = min(ans, dp[1][i]);
	printf("%d\n", ans);
	return 0;
}
