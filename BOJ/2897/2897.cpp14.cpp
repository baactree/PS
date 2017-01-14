#include "bits/stdc++.h"
using namespace std;
char Map[50][51];
int cnt[5];
int N, M;
void search(int x, int y) {
	int b, p;
	b = p = 0;
	for (int i = x; i < x + 2; i++)
		for (int j = y; j < y + 2; j++) {
			if (Map[i][j] == '#')
				b++;
			if (Map[i][j] == 'X')
				p++;
		}
	if (b != 0)
		return;
	cnt[p]++;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%s", Map[i]);
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < M - 1; j++)
			search(i, j);
	for (int i = 0; i < 5; i++)
		printf("%d\n", cnt[i]);
	return 0;
}