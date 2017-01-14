#include "bits/stdc++.h"
using namespace std;
char str[1010];
int len;
int alp_min[26], alp_max[26];
int cache[26][1000];
int search(int idx, int cur) {
	if (idx == 26)
		return 0;
	int &ret = cache[idx][cur];
	if (ret != -1)
		return ret;
	if (alp_min[idx] == alp_max[idx])
		return ret = search(idx + 1, alp_min[idx]) + abs(cur - alp_min[idx]);
	if (alp_max[idx] != -1) {
		ret = search(idx + 1, alp_min[idx]) + abs(cur - alp_max[idx]) + abs(alp_max[idx] - alp_min[idx]);
		ret = min(ret, search(idx + 1, alp_max[idx]) + abs(cur - alp_min[idx]) + abs(alp_min[idx] - alp_max[idx]));
		return ret;
	}
	return ret = search(idx + 1, cur);
}
int main() {
	memset(cache, -1, sizeof(cache));
	memset(alp_min, 0x3f, sizeof(alp_min));
	memset(alp_max, -1, sizeof(alp_max));
	cin >> str;
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		alp_min[str[i] - 'a'] = min(alp_min[str[i] - 'a'], i);
		alp_max[str[i] - 'a'] = max(alp_max[str[i] - 'a'], i);
	}
	printf("%d\n", search(0, 0)+len);
	return 0;
}