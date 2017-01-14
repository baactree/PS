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
vector<pair<int, int> >Map;
LLU sum=0;
int main() {
	int N;
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		Map.push_back(make_pair(a, b));
		sum += b;
	}
	sort(Map.begin(), Map.end());
	LLU _sum=0;
	for (int i = 0; i < N; i++) {
		_sum += Map[i].second;
		if (_sum >= (sum + 1) / 2) {
			printf("%d\n", Map[i].first);
			return 0;
		}
	}
	return 0;
}