#include "bits/stdc++.h"
using namespace std;
int arr_a[500000];
int arr_b[500000];
vector<int> ans;
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr_a[i]);
	for (int i = 0; i < M; i++)
		scanf("%d", &arr_b[i]);
	sort(arr_a, arr_a + N);
	sort(arr_b, arr_b + M);
	for (int i = 0, idx = 0; i < N; i++) {
		while (arr_a[i] > arr_b[idx] && idx != M)
			idx++;
		if (idx == M)
			ans.push_back(arr_a[i]);
		if (arr_a[i] < arr_b[idx])
			ans.push_back(arr_a[i]);
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	return 0;
}