#include "bits/stdc++.h"
using namespace std;
int N, M;
int A[1000000];
int B[1000000];
int C[2000000];
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < M; i++)
		scanf("%d", &B[i]);
	int i, j, k;
	i = j = k = 0;
	while (true) {
		if (i == N&&j == M)
			break;
		if (i == N) {
			C[k++] = B[j++];
			continue;
		}
		if (j == M) {
			C[k++] = A[i++];
			continue;
		}
		if (A[i] > B[j]) {
			C[k++] = B[j++];
			continue;
		}
		if (A[i] <= B[j]) {
			C[k++] = A[i++];
			continue;
		}
	}
	for (int i = 0; i < N + M; i++)
		printf("%d ", C[i]);
	return 0;
}