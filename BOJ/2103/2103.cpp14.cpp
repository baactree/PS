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
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
typedef unsigned long long LLU;
vector<pair<int, int> >Map_x;
vector<pair<int, int> >Map_y;
int main() {
	int x, y;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &x, &y);
		Map_x.push_back(make_pair(x, y));
		Map_y.push_back(make_pair(y, x));
	}
	sort(Map_x.begin(), Map_x.end());
	sort(Map_y.begin(), Map_y.end());
	int ans = 0;
	for (int i = 0; i < N; i+=2) {
		int a = Map_x[i].second;
		int b = Map_x[i + 1].second;
		ans += abs((b - a));
	}
	for (int i = 0; i < N; i += 2) {
		int a = Map_y[i].second;
		int b = Map_y[i + 1].second;
		ans += abs((b - a));
	}
	printf("%d\n", ans);
	return 0;
}