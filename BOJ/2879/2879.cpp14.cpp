

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int x[1002];
int dp[1002][161];

int main(void) {

	memset(dp, 0x3F, sizeof(dp));
	dp[0][0] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &x[i]);
	int in;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &in);
		x[i] -= in;
	}
	for (int i = 1; i <= n + 1; ++i)
		for (int a = 0; a <= 160; ++a)
			for (int aa = 0; aa <= 160; ++aa) {
				int b = a  + x[i - 1] ;
				int bb = aa  + x[i];
				if (b >= 0 && b <= 160 && bb >= 0 && bb <= 160)
					dp[i][aa] = min(dp[i][aa], dp[i - 1][a] + max(aa - a, 0) + max(bb - b, 0));
			}
	printf("%d\n", dp[n + 1][0]);
	return 0;
}