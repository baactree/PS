#include "bits/stdc++.h"
using namespace std;
int N;
pair<int, int> arr[100];
int lis[101];
int main() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		if (a > b) {
			arr[i].first = a;
			arr[i].second = b;
		}
		else {
			arr[i].first = b;
			arr[i].second = a;
		}
	}
	sort(arr, arr + N);
	int len = 1;
	lis[len] = arr[0].second;
	int idx = 1;
	for (int i = 1; i < N; i++) {
		int temp;
		for (temp = 1; temp <= len; temp++) {
			if (lis[temp] <= arr[i].second)
				continue;
			else
				break;
		}
		if (temp == len + 1) {
			len++;
			lis[len] = arr[i].second;
		}
		else
			lis[temp] = arr[i].second;
	}
	printf("%d\n", len);
	return 0;
}