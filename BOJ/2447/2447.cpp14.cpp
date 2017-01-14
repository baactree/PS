#include "bits/stdc++.h"
using namespace std;
int N;
bool Map[2187][2187];
void search(int x, int y, int k) {
	if (k == 1) {
		Map[x][y] = true;
		return;
	}
	int t = k / 3;
	search(x, y, t);
	search(x, y + t, t);
	search(x, y + t * 2, t);
	search(x + t, y, t);
	search(x + t, y + t * 2, t);
	search(x + t * 2, y, t);
	search(x + t * 2, y + t, t);
	search(x + t * 2, y + t * 2, t);
}
int main() {
	cin >> N;
	search(0, 0, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (Map[i][j])
				printf("*");
			else
				printf(" ");
		printf("\n");
	}
	return 0;
}