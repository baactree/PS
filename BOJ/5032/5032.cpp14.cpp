#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;
int main() {
	int e, f, c;
	cin >> e >> f >> c;
	int ans = 0;
	int t = e + f;
	int temp;
	while (t >= c) {
		temp = t / c;
		ans += temp;
		t %= c;
		t += temp;
	}
	printf("%d\n", ans);
	return 0;
}