#include "bits/stdc++.h"
using namespace std;
int Map[8][8];
int r[8], c[8],tr[8],tc[8];
char ans[8][8];
int temp[8][8];
int M, K;
int main() {
	cin >> M >> K;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			scanf("%d", &Map[i][j]);
			ans[i][j] = '.';
			temp[i][j] = M;
		}
	for (int i = 0; i < 8; i++) {
		int sum = 0;
		for (int j = 0; j < 8; j++) {
			sum += Map[i][j];
		}
		r[i] = sum;
	}
	for (int i = 0; i < 8; i++) {
		int sum = 0;
		for (int j = 0; j < 8; j++) {
			sum += Map[j][i];
		}
		c[i] = sum;
	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			int now = r[i] + c[j] - Map[i][j];
			if ((M + now) & 1) {
				ans[i][j] = '-';
				for (int k = 0; k < 8; k++)
					temp[i][k]--;
				for (int k = 0; k < 8; k++)
					temp[k][j]--;
				temp[i][j]++;
			}
		}
	for (int i = 0; i < 8; i++) {
		int sum = 0;
		for (int j = 0; j < 8; j++) {
			sum += temp[i][j];
		}
		tr[i] = sum;
	}
	for (int i = 0; i < 8; i++) {
		int sum = 0;
		for (int j = 0; j < 8; j++) {
			sum += temp[j][i];
		}
		tc[i] = sum;
	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (ans[i][j] == '-') {
				int now = r[i] + c[j] - Map[i][j];
				int tnow = tr[i] + tc[j] - temp[i][j];
				if (now % 4 != tnow % 4)
					ans[i][j] = '+';
			}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			printf("%c ", ans[i][j]);
		printf("\n");
	}
	return 0;
}
