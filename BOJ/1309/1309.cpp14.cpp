#include "bits/stdc++.h"
using namespace std;
#define X 9901
int N;
int cache[100000][2];
int search(int idx, bool emp) {
	if (idx == N)
		return 1;
	int &ret = cache[idx][emp];
	if (ret != -1)
		return ret;
	ret = 0;
	if (!emp)
		ret = (ret + search(idx + 1, true)) % X;
	ret = (ret + search(idx + 1, true)) % X;
	ret = (ret + search(idx + 1, false)) % X;
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	printf("%d\n", search(0, 0));
}