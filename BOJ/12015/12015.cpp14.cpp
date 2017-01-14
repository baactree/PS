#include "bits/stdc++.h"
using namespace std;
int arr[1000000];
int lis[1000001];
int N, len, temp;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++) {
		temp = lower_bound(lis, lis + len, arr[i]) - lis;
		if (temp == len)
			len++;
		lis[temp] = arr[i];
	}
	printf("%d\n", len);
	return 0;
}