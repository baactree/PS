#include "bits/stdc++.h"
using namespace std;
int par[10000];
int child[10000][2];
int trip[10000], ans;
int N;
void dfs(int v, int dist,int fi) {
	if (v == 0||trip[v])
		return;
	trip[v] = true;
	if (v == fi)
		ans = dist;
	dfs(par[v], dist + 1, fi);
	dfs(child[v][0], dist + 1, fi);
	dfs(child[v][1], dist + 1, fi);
}
int main() {
	cin >> N;
	int in;
	int idx = N + 1;
	for (int i = 1; i < N; i++) {
		scanf("%d", &in);
		int temp = i;
		if (par[i] == 0) {
			par[i] = idx;
			child[idx][0] = i;
			idx++;
		}
		temp = par[i];
		in--;
		for (int i = 0; i < in; i++) {
			if (child[temp][0] == 0) {
				child[temp][0] = idx;
				par[idx] = temp;
				temp = idx;
				idx++;
			}
			else if(child[temp][1]==0){
				child[temp][1] = idx;
				par[idx] = temp;
				temp = idx;
				idx++;
			}
			else if (par[temp] == 0) {
				par[temp] = idx;
				child[idx][0] = temp;
				temp = idx;
				idx++;
			}
			else {
				temp = par[temp];
			}
		}
		int p = par[temp];
		par[i + 1] = p;
		if (child[p][0] == temp) {
			child[p][0] = i + 1;
		}
		else {
			child[p][1] = i + 1;
		}
	}
	int a, b;
	scanf("%d%d", &a, &b);
	dfs(a,0,b);
	printf("%d\n", ans);
	return 0;
}