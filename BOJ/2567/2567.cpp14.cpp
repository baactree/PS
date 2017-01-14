#include "bits/stdc++.h"
using namespace std;
bool Map[110][110];
bool trip[110][110];
void chk(int x, int y) {
	for (int i = x; i < x + 10; i++)
		for (int j = y; j < y + 10; j++)
			Map[i][j] = true;
}
queue<pair<int, int> >q;
bool safe(int x, int y) {
	return (x >= 0 && x < 110 && y >= 0 && y <= 110);
}
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	int N;
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		a++; b++;
		chk(a, b);
	}
	int ans = 0;
	for (int i = 0; i < 110; i++)
		for (int j = 0; j < 110; j++)
			if (Map[i][j]) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (safe(nx, ny) && !Map[nx][ny])
						ans++;
				}
			}
	printf("%d\n", ans);
	return 0;
}