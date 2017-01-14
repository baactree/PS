#include <bits/stdc++.h>
using namespace std;
int N;
int lis[100001];
int len;
int r, l, mid, _size;
int main() {
	while (scanf("%d", &N) == 1) {
		int in;
		scanf("%d", &in);
		lis[1] = in;
		len = 1;
		for (int i = 1; i < N; i++) {
			scanf("%d", &in);
			l = 1;
			r = len;
			_size = 0;
			while (r >= l) {
				mid = (r + l) / 2;
				if (lis[mid]<in) {
					_size = max(_size, mid);
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
			if (_size == len) {
				len++;
				lis[len] = in;
			}
			else {
				lis[_size + 1] = in;
			}
		}
		printf("%d\n", len);
	}
	return 0;
}