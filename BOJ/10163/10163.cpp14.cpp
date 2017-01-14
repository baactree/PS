#include "bits/stdc++.h"
using namespace std;
int Map[110][110];
int ans[101];
void color(int x, int y, int w, int h,int d) {
	for (int i = x; i < x + w; i++)
		for (int j = y; j < y + h; j++)
			Map[i][j] = d;
}
int main() {
	int N;
	int a, b, c, d;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		color(a, b, c, d, i);
	}
	for (int i = 0; i < 110; i++)
		for (int j = 0; j < 110; j++)
			ans[Map[i][j]]++;
	for (int i = 1; i <= N; i++)
		printf("%d\n", ans[i]);
	return 0;
}