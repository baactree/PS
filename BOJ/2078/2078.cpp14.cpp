#include "bits/stdc++.h"
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int r, l;
	r = l = 0;
	while (a != b) {
		if (a > b) {
			if (b != 1) {
				l += a / b;
				a %= b;
			}
			else {
				l += (a / b) - 1;
				a = 1;
			}
		}
		else {
			if (a != 1) {
				r += b / a;
				b %= a;
			}
			else {
				r += (b / a) - 1;
				b = 1;
			}
		}
	}
	printf("%d %d\n", l, r);
	return 0;
}