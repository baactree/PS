#include "bits/stdc++.h"
using namespace std;
typedef long long int llu;
int N;
int arr[100];
llu cache[100][21];
llu search(int idx, int sum) {
	if (sum < 0 || sum>20)
		return 0;
	if (idx == N - 1) {
		if (sum == arr[idx])
			return 1;
		return 0;
	}
	llu &ret = cache[idx][sum];
	if (ret != -1)
		return ret;
	ret = 0;
	ret += search(idx + 1, sum + arr[idx]);
	ret += search(idx + 1, sum - arr[idx]);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	printf("%lld\n", search(1, arr[0]));
	return 0;
}