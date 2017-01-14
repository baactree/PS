#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int UL;
UL len[10000];
int K, N;
UL search(UL left, UL right) {
	UL mid = (left + right) / 2;
	if (left == right) {
		UL n = 0;
		for (int i = 0; i < K; i++)
			n += len[i] / mid;
		if (n == N)
			return left;
		else
			return left - 1;
	}
	UL n = 0;
	for (int i = 0; i < K; i++)
		n += len[i] / mid;
	if (n < N) {
		search(left, mid);
	}
	else {
		search(mid + 1, right);
	}
}
int main() {
	cin >> K >> N;
	for (int i = 0; i < K; i++)
		scanf("%d", &len[i]);
	printf("%llu\n", search(0, 0xffffffff));
	return 0;
}