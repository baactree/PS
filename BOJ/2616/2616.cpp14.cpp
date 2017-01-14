#include "bits/stdc++.h"
using namespace std;
int N,K;
int arr[50000];
vector<int> sum;
int cache[50000][3];
int search(int idx, int cnt) {
	if (cnt==3||idx>=sum.size())
		return 0;
	int &ret = cache[idx][cnt];
	if (ret != -1)
		return ret;
	ret = search(idx + 1, cnt);
	ret = max(ret, search(idx + K, cnt + 1) + sum[idx]);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	int temp = 0;
	for (int i = 0; i < N; i++) 
		scanf("%d", &arr[i]);
	cin >> K;
	for (int i = 0; i < N; i++) {
		if (i < K-1)
			temp += arr[i];
		else {
			temp += arr[i];
			sum.push_back(temp);
			temp -= arr[i - K + 1];
		}
	}
	printf("%d\n", search(0, 0));
	return 0;
}