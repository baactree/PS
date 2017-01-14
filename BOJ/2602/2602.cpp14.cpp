#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;
char scroll[22];
char devil[102];
char angel[102];
int blen;
int clen;
int cache[2][100][20];
int search(bool mode, int bidx, int cidx) {
	if (cidx == clen)
		return 1;
	if (bidx == blen)
		return 0;
	int &ret = cache[mode][bidx][cidx];
	if (ret != -1)
		return ret;
	ret = 0;
	if (mode) {
		for (int i = bidx + 1; i < blen; i++)
			if (devil[i] == scroll[cidx])
				ret += search(0, i, cidx + 1);
	}
	else {
		for (int i = bidx + 1; i < blen; i++)
			if (angel[i] == scroll[cidx])
				ret += search(1, i, cidx + 1);
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%s%s%s", &scroll[1], &devil[1], &angel[1]);
	scroll[0] = devil[0] = angel[0] = 1;
	clen = strlen(scroll);
	blen = strlen(devil);
	printf("%d\n", search(0, 0, 1) + search(1, 0, 1));
	return 0;
}