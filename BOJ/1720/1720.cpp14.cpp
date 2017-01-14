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
int dp[31];
int ans[31];
int main(){
	cin >> N;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
	for (int i = 3; i <= N; i++) {
		if (i % 2 == 0) {
			ans[i] = dp[i] - dp[i / 2] - dp[i / 2 - 1] * 2;
		}
		else {
			ans[i] = dp[i] - dp[i / 2];
		}
	}
	ans[1] = 0;
	ans[2] = 0;
	printf("%d\n", dp[N]-ans[N]/2);
	return 0;
}