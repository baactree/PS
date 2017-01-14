#include "bits/stdc++.h"
using namespace std;
const double PI = 2.0*acos(0.0);
const unsigned long long int mod = 1000000000000000000;
int N;
map<double, unsigned long long int> Map;
unsigned long long int search(double N) {
	if (N >= 0 && N <= PI)
		return 1;
	if (Map[N] != 0)
		return Map[N];
	return Map[N]=(search(N-1)+search(N-PI))%mod;
}
int main() {
	cin >> N;
	printf("%llu\n",search(N));
	return 0;
}