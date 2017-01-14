#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>


using namespace std;
typedef long long int ll;
int main()
{
	ll N;
	cin >> N;
	ll ans=N;
	for (ll i = 2; i*i <= N; i++) {
		if (N%i == 0) {
			while (N%i == 0)
				N /= i;
			ans -= ans / i;
		}
	}
	if (N > 1)
		ans -= ans / N;
	printf("%lld\n", ans);
	return 0;
}