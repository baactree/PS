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
int N;
int f[1000];
int g[1000];
int k[1000];
int main() {
	int Case;
	f[0] = 1;
	f[1] = 1;
	g[0] = 0;
	g[1] = 1;
	k[0] = 0;
	k[1] = 1;
	for (int i = 2; i < 1000; i++) {
		f[i] = f[i - 2] + g[i - 1] * 2+k[i-1]+f[i-1];
		g[i] = f[i - 1] + g[i - 1];
		k[i] = f[i - 1] + k[i - 2];
	}
	cin >> Case;
	while (Case--)
	{
		cin >> N;
		printf("%d\n", f[N]);
	}
	return 0;
}