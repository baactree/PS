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
int lesson[100000];


bool search(int data) {
	int m = M;
	int idx = 0;
	while (m != 0) {
		int sum = 0;
		while (idx!=N) {
			if (sum + lesson[idx] <= data)
				sum += lesson[idx++];
			else
				break;
		}	
		m--;
	}
	if (idx == N)
		return true;
	else
		return false;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%d", &lesson[i]);
	int r, l, mid;
	r = 1000000000;
	l = 1;
	int ans = 987654321;
	while (r >= l) {
		mid = (r + l) / 2;
		if (search(mid)) {
			ans = min(ans, mid);
			r= mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	printf("%d\n", ans);

	return 0;

}