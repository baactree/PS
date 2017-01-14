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
int N, M;
int _tree[1000000];
int search(int left, int right) {
	int mid = (left + right) / 2;
	if (left == right) {
		unsigned long long int m = 0;
		for (int i = 0; i < N; i++)
			m += (_tree[i] - mid) < 0 ? 0 : _tree[i] - mid;
		if (m >= M)
			return mid;
		else
			return -987654321;
	}
	unsigned long long int m = 0;
	for (int i = 0; i < N; i++)
		m += (_tree[i] - mid) < 0 ? 0 : _tree[i] - mid;
//	cout << left << "//" << right << "//" << mid << "//" << m << endl;
	if (m < M)
		return search(left, mid);
	else 
		return max(mid,search(mid + 1, right));
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		scanf("%d", &_tree[i]);
	}
	printf("%d\n", search(1, 1000000000));
	return 0;
}