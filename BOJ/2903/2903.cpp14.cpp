#include "bits/stdc++.h"
using namespace std;
int main() {
	int N;
	cin >> N;
	long long now = 2;
	while (N--) {
		now = now + now - 1;
	}
	printf("%lld\n", now*now);
	return 0;
}