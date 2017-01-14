#include "bits/stdc++.h"
using namespace std;
int num(char in) {
	if (in >= 'A'&&in <= 'C')
		return 2;
	if (in >= 'D'&&in <= 'F')
		return 3;
	if (in >= 'G'&&in <= 'I')
		return 4;
	if (in >= 'J'&&in <= 'L')
		return 5;
	if (in >= 'M'&&in <= 'O')
		return 6;
	if (in >= 'P'&&in <= 'S')
		return 7;
	if (in >= 'T'&&in <= 'V')
		return 8;
	if (in >= 'W'&&in <= 'Z')
		return 9;
}
int main() {
	char str[16];
	scanf("%s", str);
	int len = strlen(str);
	int ans = 0;
	for (int i = 0; i < len; i++)
		ans += num(str[i]) + 1;
	printf("%d\n", ans);
	return 0;
}