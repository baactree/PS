#include "bits/stdc++.h"
using namespace std;
int N;
int Map[10][10];
int per[10];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &Map[i][j]);
	for (int i = 0; i < N; i++)
		per[i] = i;
	int ans = 1000000010;
	while (true) {
		int temp = 0;
		for (int i = 1; i < N; i++) {
			int a, b;
			a = per[i - 1];
			b = per[i];
			if(Map[a][b]!=0)
				temp += Map[a][b];
			else {
				temp = 1000000011;
				break;
			}
		}
		if (Map[per[N - 1]][0] != 0)
			temp += Map[per[N - 1]][0];
		else
			temp = 1000000011;
		ans = min(ans, temp);
		if (!next_permutation(per + 1, per + N))
			break;
	}
	printf("%d\n", ans);
	return 0;
}