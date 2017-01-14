#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;
int R, C;
int Map[1000][1000];
char ans[1000100];

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			scanf("%d", &Map[i][j]);
	if (R & 1) {
		int idx = 0;
		for (int i = 0; i < R / 2; i++) {
			for (int i = 0; i < C - 1; i++)
				ans[idx++] = 'R';
			ans[idx++] = 'D';
			for (int i = 0; i < C - 1; i++)
				ans[idx++] = 'L';
			ans[idx++] = 'D';
		}
		for (int i = 0; i < C - 1; i++)
			ans[idx++] = 'R';
		ans[idx] = '\0';
		printf("%s\n", ans);
	}
	else if (C & 1) {
		int idx = 0;
		for (int i = 0; i < C / 2; i++) {
			for (int i = 0; i < R - 1; i++)
				ans[idx++] = 'D';
			ans[idx++] = 'R';
			for (int i = 0; i < R - 1; i++)
				ans[idx++] = 'U';
			ans[idx++] = 'R';
		}
		for (int i = 0; i < R - 1; i++)
			ans[idx++] = 'D';
		ans[idx] = '\0';
		printf("%s\n", ans);
	}
	else {
		int minx, miny;
		int Min = 987654321;
		int idx = 0;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				if ((i + j) & 1) {
					if (Map[i][j] < Min) {
						Min = Map[i][j];
						minx = i;
						miny = j;
					}
				}
			}
		for (int i = 0; i < R; i += 2) {
			if (minx >= i&&minx <= i + 1) {
				for (int j = 0; j < C; j += 2) {
					if (miny >= j&&miny <= j + 1) {
						if (minx-i> miny-j) {
							ans[idx++] = 'R';
							ans[idx++] = 'D';
							if (j + 2 != C)
								ans[idx++] = 'R';
							else if (i + 2 != R)
								ans[idx++] = 'D';
						}
						else {
							ans[idx++] = 'D';
							ans[idx++] = 'R';
							if (j + 2 != C)
								ans[idx++] = 'R';
							else if (i + 2 != R)
								ans[idx++] = 'D';
						}
					}
					else if (miny > j) {
						ans[idx++] = 'D';
						ans[idx++] = 'R';
						ans[idx++] = 'U';
						ans[idx++] = 'R';
					}
					else if (miny < j) {
						ans[idx++] = 'U';
						ans[idx++] = 'R';
						ans[idx++] = 'D';
						if (j + 2 != C) 
							ans[idx++] = 'R';
						else if (i + 2 != R)
							ans[idx++] = 'D';
					}
				}
			}
			else if (minx > i) {
				for (int j = 0; j < C - 1; j++)
					ans[idx++] = 'R';
				ans[idx++] = 'D';
				for (int j = 0; j < C - 1; j++)
					ans[idx++] = 'L';
				ans[idx++] = 'D';
			}
			else if (minx < i) {
				for (int j = 0; j < C - 1; j++)
					ans[idx++] = 'L';
				ans[idx++] = 'D';
				for (int j = 0; j < C - 1; j++)
					ans[idx++] = 'R';
				if (i + 2 != R)
					ans[idx++] = 'D';
			}
		}
		ans[idx] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}