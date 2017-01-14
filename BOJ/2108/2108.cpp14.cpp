#include "bits/stdc++.h"
using namespace std;
int arr[500000];
int cnt[8001];
int N;
vector<int> cnt_vec;
int main() {
	cin >> N;
	double sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		cnt[arr[i] + 4000]++;
	}
	sum /= N;
	sort(arr, arr + N);
	int max_cnt = 0;
	for (int i = 0; i < 8001; i++) {
		if (max_cnt == cnt[i])
			cnt_vec.push_back(i - 4000);
		if (max_cnt < cnt[i]) {
			max_cnt = cnt[i];
			cnt_vec.clear();
			cnt_vec.push_back(i - 4000);
		}
	}
	sort(cnt_vec.begin(), cnt_vec.end());
	printf("%d\n", sum>0?(int)(sum+0.5):(int)(sum-0.5));
	printf("%d\n", arr[N / 2]);
	if (cnt_vec.size() > 1) {
		printf("%d\n", cnt_vec[1]);
	}
	else
		printf("%d\n", cnt_vec[0]);
	printf("%d\n", arr[N-1] - arr[0]);
	return 0;
}