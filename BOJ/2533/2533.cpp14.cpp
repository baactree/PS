#include "bits/stdc++.h"
using namespace std;
int N;
vector<int> Map[1000001];
bool trip[1000001];
int cache[1000001][2];
int search(int here,int par,bool ada) {
	int &ret = cache[here][ada];
	if (ret != -1)
		return ret;
	ret = 0x7fffffff;
	if (ada) {
		ret = 0;
		for (int i = 0; i < Map[here].size(); i++) {
			int there = Map[here][i];
			if (there == par)
				continue;
			ret += search(there, here, 0);
		}
	}
	int temp = 1;
	for (int i = 0; i < Map[here].size(); i++) {
		int there = Map[here][i];
		if (there == par)
			continue;
		temp += search(there, here, 1);
	}
	ret = min(ret, temp);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &a, &b);
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	printf("%d\n", search(1,0,1));
	return 0;
}