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
using namespace std;

vector<pair<int, int> >line;
int main() {
	int N;
	cin >> N;
	unsigned long long ans = 0;
	unsigned long long int cnt = 0;
	int st, fi;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &st, &fi);
		line.push_back(make_pair(st, 0));
		line.push_back(make_pair(fi, 1));
	}
	sort(line.begin(), line.end());
	int start = -1;
	for (int i = 0; i < 2 * N; i++) {
		if (line[i].second == 0) {
			if (start == -1)
				start = line[i].first;
			cnt++;
		}
		else {
			cnt--;
			if (cnt == 0&&start!=-1) {
				ans += line[i].first - start;
				start = -1;
			}
		}
	}
	printf("%llu\n", ans);
	return 0;
}