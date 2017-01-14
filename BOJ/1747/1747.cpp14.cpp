#include "bits/stdc++.h"
using namespace std;
int N;
bool pel(int n) {
	string a = to_string(n);
	string b = a;
	reverse(b.begin(), b.end());
	if (a == b)
		return true;
	return false;
}
bool prime(int n) {
	if (n == 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i*i <= n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}
int main() {
	cin >> N;
	for (int i = N;; i++) {
		if (pel(i)&&prime(i)) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}