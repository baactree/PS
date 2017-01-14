#include "bits/stdc++.h"
using namespace std;
int out[30];
int in[30];
int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &in[i]);
	int idx = 0;
	int value = 0;
	for (int i = 0; i < N; i++) {
		while (out[(idx + value) % N] != 0)
			idx++;
		out[(idx + value)%N] = in[i];
		idx = (idx + value) % N;
		value = in[i];
	}
	printf("%d\n", N);
	for (int i = 0; i < N; i++)
		printf("%d ", out[i]);
	printf("\n");
	return 0;
}