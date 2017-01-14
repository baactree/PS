#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <deque>
#include <stack>
#include <cmath>
using namespace std;
int T, W;
int fall[1000];
int cache[3][1001][31];
int search(int loc, int _time, int move) {
	if (_time == T)
		return 0;
	int& ret=cache[loc][_time][move];
	if (ret != -1)
		return ret;
	int fall_loc = fall[_time];
	if (fall_loc == loc) {
		ret=search(loc, _time + 1, move) + 1;
	}
	else {
		if (move != W)
			ret = search(fall_loc, _time + 1, move + 1) + 1;
		ret = max(ret, search(loc, _time + 1, move));
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> T >> W;
	for (int i = 0; i < T; i++)
		scanf("%d", &fall[i]);
	printf("%d\n", search(1, 0, 0));
	return 0;
}