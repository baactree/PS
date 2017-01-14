#include "bits/stdc++.h"
using namespace std;
map<string, string> arr;
map<string, int> cnt;
string a, b;
char input[2][21];
string find(string x) {
	if (arr.count(x) == 0 || arr[x] == x)
		return arr[x] = x;
	return arr[x] = find(arr[x]);
}
void _union(string x, string y) {
	x = find(x);
	y = find(y);
	arr[y] = x;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		arr.clear();
		cnt.clear();
		int F;
		scanf("%d", &F);
		for (int i = 0; i < F; i++) {
			scanf("%s%s", input[0], input[1]);
			a = input[0], b = input[1];
			if (cnt.count(a) == 0)
				cnt[a] = 1;
			if (cnt.count(b) == 0)
				cnt[b] = 1;
			a = find(a);
			b = find(b);
			_union(a, b);
			if(a!=b)
				cnt[a] += cnt[b];
			printf("%d\n", cnt[a]);
		}
	}
	return 0;
}