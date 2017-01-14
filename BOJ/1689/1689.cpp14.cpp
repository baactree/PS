#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int N;
vector < pair<int, bool> >  _event;
int main() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		_event.push_back(make_pair(a, 1));
		_event.push_back(make_pair(b, 0));
	}
	sort(_event.begin(), _event.end());
	int ans = -1;
	int cnt = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (_event[i].second) {
			cnt++;
			ans = max(ans, cnt);
		}
		else {
			cnt-- ;
			ans = max(ans, cnt);
		}
	}
	printf("%d\n", ans);
	return 0;
}