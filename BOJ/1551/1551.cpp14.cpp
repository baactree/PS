#include "bits/stdc++.h"
using namespace std;
int N, K;
int arr[20];
int ans[20];
int main() {
    scanf("%d%d",&N,&K);
	for (int i = 0; i < N; i++) 
		scanf("%d,",&arr[i]);
       while (K--) {
		N--;
		for (int i = 0; i < N; i++)
			arr[i] = arr[i + 1] - arr[i];
	}
	for (int i = 0; i < N; i++) {
		printf("%d", arr[i]);
		if (i != N - 1)
			printf(",");
	}
	printf("\n");
	return 0;
}