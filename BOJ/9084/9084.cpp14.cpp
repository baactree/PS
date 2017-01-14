#include "bits/stdc++.h"
using namespace std;
int N, K;
int arr[20];
int cache[20][10001];
int search(int idx, int sum) {
	if (sum > K)
		return 0;
	if (idx == N) 
		return sum == K;
	int &ret = cache[idx][sum];
	if (ret != -1)
		return ret;
	ret = search(idx + 1, sum);
	ret += search(idx, sum + arr[idx]);
	return ret;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		scanf("%d", &K);
		printf("%d\n", search(0, 0));
	}
	return 0;
}
