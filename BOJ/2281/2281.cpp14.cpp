#include "bits/stdc++.h"
using namespace std;
int N, M;
int arr[1000];
int cache[1000][1001];
int search(int idx, int sum) {
	if (idx == N)
		return 0;
	int& ret = cache[idx][sum];
    if(ret!=-1)
        return ret;
	if (sum == 0) 
		return ret = search(idx+1, sum + arr[idx]);
	if (sum + arr[idx] + 1 > M)
		return ret = search(idx, 0) + (M - sum)*(M - sum);
	ret = search(idx + 1, sum + 1 + arr[idx]);
	ret = min(ret, search(idx, 0) + (M - sum)*(M - sum));
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", search(0, 0));
	return 0;
}