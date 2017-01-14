#include "bits/stdc++.h"
using namespace std;
int N;
char Map[51][5][8];
int search(int a, int b) {
	int cnt = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 7; j++)
			if (Map[a][i][j] != Map[b][i][j])
				cnt++;
	return cnt;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 5; j++)
			scanf("%s", Map[i][j]);
	}
	pair<int, int> ans;
	int min_cnt = 0x7fffffff;
	int temp;
	for (int i = 1; i < N; i++)
		for (int j = i + 1; j <= N; j++) {
			temp = search(i, j);
			if (min_cnt > temp) {
				ans.first = i;
				ans.second = j;
				min_cnt = temp;
			}
		}
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}