#include "bits/stdc++.h"
using namespace std;
int arr[100000][3];
int N;
int cache[100000][3];
int search(int idx, int col) {
	int &ret = cache[idx][col];
	if (ret != -1)
		return ret;
	if (idx == 0) {
		if (col == 1)
			return ret=arr[idx][col];
		if (col == 2)
			return ret = search(idx, 1) + arr[idx][col];
	}
	if (idx == 1) {
		if (col == 0) {
			ret = search(idx - 1, 1)+arr[idx][col];
			return ret;
		}
		if (col == 1) {
			ret = search(idx - 1, 1) + arr[idx][col];
			ret = min(ret, search(idx - 1, 2) + arr[idx][col]);
			ret = min(ret, search(idx, 0) + arr[idx][col]);
			return ret;
		}
		if (col == 2) {
			ret = search(idx, 1) + arr[idx][col];
			ret = min(ret, search(idx - 1, 2) + arr[idx][col]);
			ret = min(ret, search(idx - 1, 1) + arr[idx][col]);
			return ret;
		}
	}
	if (col == 0) {
		ret = search(idx - 1, 0) + arr[idx][col];
		ret = min(ret, search(idx - 1, 1) + arr[idx][col]);
		return ret;
	}
	if (col == 1) {
		ret = search(idx, 0) + arr[idx][col];
		ret = min(ret, search(idx - 1, 1) + arr[idx][col]);
		ret = min(ret, search(idx - 1, 2) + arr[idx][col]);
		ret = min(ret, search(idx - 1, 0) + arr[idx][col]);

		return ret;
	}
	ret = search(idx, 1) + arr[idx][col];
	ret = min(ret, search(idx - 1, 1) + arr[idx][col]);
	ret = min(ret, search(idx - 1, 2) + arr[idx][col]);
	return ret;
}
int main() {
	int cnt = 0;
	while (true) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		cnt++;
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 3; j++)
				scanf("%d", &arr[i][j]);
		printf("%d. %d\n", cnt, search(N - 1, 1));
	}
	return 0;
}