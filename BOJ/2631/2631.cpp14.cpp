#include "bits/stdc++.h"
using namespace std;
vector<int> lis;
vector<int>::iterator it;
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int in = 0;
		scanf("%d", &in);
		it = lower_bound(lis.begin(), lis.end(), in);
		if (it == lis.end())
			lis.push_back(in);
		else
			*it = in;
	}
	printf("%d\n", N - lis.size());
	return 0;
}