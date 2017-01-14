#include "bits/stdc++.h"
using namespace std;
int N;
short Map[2187][2187];
int cnt[3];
bool chk(int x, int y, int k) {
	int now = Map[x][y];
	for (int i = x; i < x + k; i++)
		for (int j = y; j < y + k; j++)
			if (now != Map[i][j])
				return false;
	return true;
}
void search(int x, int y, int k) {
	if (chk(x, y, k)) {
		cnt[Map[x][y]+1]++;
		return;
	}
	int t = k / 3;
	search(x, y, t);
	search(x, y + t, t);
	search(x, y + 2 * t, t);
	search(x + t, y, t);
	search(x + t, y + t, t);
	search(x + t, y + t * 2, t);
	search(x + t * 2, y, t);
	search(x + t * 2, y + t, t);
	search(x + t * 2, y + t * 2, t);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &Map[i][j]);
	search(0, 0, N);
	for (int i = 0; i < 3; i++)
		printf("%d\n", cnt[i]);
	return 0;
}