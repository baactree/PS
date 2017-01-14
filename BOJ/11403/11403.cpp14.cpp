#include "bits/stdc++.h"
using namespace std;
int vertex[100][100];
int n;
int main() {
	memset(vertex, 0x3f, sizeof(vertex));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int in;
			scanf("%d", &in);
			if (in)
				vertex[i][j] = in;
		}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (vertex[i][j]>vertex[i][k] + vertex[k][j])
					vertex[i][j] = vertex[i][k] + vertex[k][j];
			}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", vertex[i][j] == 0x3f3f3f3f ? 0 : 1);
		printf("\n");
	}
	return 0;
}