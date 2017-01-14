#include "bits/stdc++.h"
using namespace std;
struct bus {
	int st;
	int fi;
	bool dir;
	int idx;
};
bus busline[500001];
int N, M;
bool cmp(const bus &a, const bus &b) {
	if (a.st == b.st)
		if (a.dir == b.dir)
			return a.fi > b.fi;
		else
			return a.dir < b.dir;
	return a.st < b.st;
}
bool del[500001];
int main() {
	int max_fi = -1;
	cin >> N >> M;
	int a, b;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &a, &b);
		busline[i].st = a;
		busline[i].fi = b;
		busline[i].dir = a < b;
		busline[i].idx = i;
		if (a > b)
			max_fi = max(max_fi, b);
	}
	sort(busline + 1, busline + 1 + M, cmp);
	for (int i = 1; i <= M; i++) {
		if (busline[i].dir) {
			if (busline[i].fi > max_fi)
				max_fi = busline[i].fi;
			else
				del[busline[i].idx] = true;
		}
		else {
			if (busline[i].fi + N > max_fi)
				max_fi = busline[i].fi + N;
			else
				del[busline[i].idx] = true;
		}
	}
	for (int i = 1; i <= M; i++)
		if (!del[i])
			printf("%d ", i);
	return 0;
}