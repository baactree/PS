#include "bits/stdc++.h"

using namespace std;
int N;
int cache[100][10][1 << 10];
#define X 1000000000
int search(int idx, int before, int state) {
	if (before == -1 || before == 10)
		return 0;
	if (idx == N&&state == (1 << 10) - 1)
		return 1;
	if (idx == N)
		return 0;
	int &ret = cache[idx][before][state];
	if (ret != -1)
		return ret;
	if (idx==0) {
		ret = 0;
		for (int i = 1; i <= 9; i++)
			ret =(ret+ search(idx + 1, i, state | (1 << i)))%X;
		return ret;
	}
	ret = 0;
	ret =(ret+ search(idx + 1, before - 1, state | (1 << before - 1)))%X;
	ret =(ret+ search(idx + 1, before + 1, state | (1 << before + 1)))%X;
	return ret%X;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cout << search(0, 0, 0) << endl;
	return 0;
}