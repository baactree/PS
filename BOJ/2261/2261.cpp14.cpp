#include "bits/stdc++.h"
using namespace std;
int N;
pair<int, int> arr[100000];
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}
int dist(const pair<int,int>& a, const pair<int,int>& b) {
	int i = a.first - b.first;
	int j = a.second - b.second;
	return i*i + j*j;
}
int es(int left, int right) {
	int ret = 1e9;
	for (int i = left; i <= right; i++)
		for (int j = i + 1; j <= right; j++)
			ret = min(ret, dist(arr[i], arr[j]));
	return ret;
}
int search(int left, int right) {
	int n = right - left + 1;
	if (n <= 3) 
		return es(left, right);
	int mid = (left + right) / 2;
	int ret_left = search(left, mid);
	int ret_right = search(mid + 1, right);
	int ret = min(ret_left, ret_right);
	vector<pair<int, int> > p;
	for (int i = left; i <= right; i++) {
		int d = arr[i].first - arr[mid].first;
		if (d*d < ret)
			p.push_back(arr[i]);
	}
	sort(p.begin(), p.end(), cmp);
	for (int i = 0; i < p.size(); i++)
		for (int j = i + 1; j < p.size(); j++) {
			int t = p[i].second - p[j].second;
			if (t*t < ret)
				ret = min(ret, dist(p[i], p[j]));
			else
				break;
		}
	return ret;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	sort(arr, arr + N);
	printf("%d\n", search(0, N - 1));
	return 0;
}