#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <deque>
using namespace std;
int N, C;
int _iptime[200000];

int _search(int left, int right, int data) {
	if (left >= N)
		return -1;
	int mid = (left + right) / 2;
	if (left == right) {
		if (_iptime[left] >= data)
			return left;
		else
			return -1;
	}
	if (_iptime[mid] == data)
		return mid;
	if (_iptime[mid] > data)
		return _search(left, mid, data);
	else
		return _search(mid + 1, right, data);
}

extern inline bool search(int data) {
	int idx = 0;
	int c = C;
	int _find = _iptime[idx]+data;
	c--;
	while (c != 0) {
		idx = _search(idx+1, N-1, _find);
		if (idx == -1)
			return false;
		_find = _iptime[idx] + data;
		c--;
	}
	return true;
}

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++)
		scanf("%d", &_iptime[i]);
	sort(_iptime, _iptime + N);
	int r, l,mid;
	r = 1000000000;
	l = 1;
	int ans = 0;
	while (l<=r) {
		mid = (l + r) / 2;
		if (search(mid)) {
			if (ans < mid) {
				ans = mid;
			}
			l = mid + 1;
		}
		else {
			r = mid - 1 ;
		}
	}
	printf("%d\n", ans);
	return 0;
}