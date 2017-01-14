#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ll;
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int K, N;
		cin >> K >> N;
		unsigned long long int sum = 0;
		unsigned long long int osum = 0;
		unsigned long long int esum = 0;
		for (ll i = 1; i <= N; i++)
			sum += i;
		for (ll i = 0, temp = 1; i < N; i++, temp += 2)
			osum += temp;
		for (ll i = 0, temp = 2; i < N; i++, temp += 2)
			esum += temp;
		printf("%d %llu %llu %llu\n", K, sum, osum, esum);
	}
	return 0;
}