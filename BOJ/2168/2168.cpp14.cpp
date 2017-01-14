#include "bits/stdc++.h"
using namespace std;
int x, y;
int gcd(int a, int b) {
	return b ? gcd(b,a%b) : a;
}
int main() {
	cin >> x >> y;
	int k = gcd(x, y);
	x /= k;
	y /= k;
	printf("%d\n", (x+y-1)*k);
	return 0;
}