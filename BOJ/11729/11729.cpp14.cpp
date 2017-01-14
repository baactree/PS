#include "bits/stdc++.h"
using namespace std;
vector<pair<int, int> > ans;
void search(int n, int loc, int loc2,int loc3) {
	if (n == 1) {
		ans.push_back({ loc,loc2 });
		return;
	}
	search(n - 1, loc, loc3, loc2);
	ans.push_back({ loc, loc2 });
	search(n - 1, loc3, loc2, loc);
}
int main() {
	int N;
	cin >> N;
	search(N, 1, 3, 2);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}