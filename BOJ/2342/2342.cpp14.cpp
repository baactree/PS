/////////////////////////////////////////////////////
#ifdef _DEBUG
#include "bits_stdc++.h"
#else
#include "bits/stdc++.h"
#endif
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
typedef vector<int>::iterator It;
#define INF 0x3f3f3f3f
#define UINF 0xffffffffu
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////


vector<int> arr;
int cache[100000][5][5];
inline static int calc(int a, int b) {
	if (a == 0 || b == 0)
		return 2;
	if (a == b)
		return 1;
	a += 3;
	b += 3;
	if (a % 4 == (b - 1) % 4 || a % 4 == (b + 1) % 4)
		return 3;
	return 4;
}
int search(int idx, int left, int right) {
	if (idx!=0&&left == right)
		return INF;
	if (idx == arr.size())
		return 0;
	int &ret = cache[idx][left][right];
	if (ret != -1)
		return ret;
	ret = search(idx + 1, arr[idx], right)+calc(arr[idx],left);
	ret = min(ret, search(idx + 1, left, arr[idx])+calc(arr[idx],right));
	return ret;
}
int main() {
	while (true) {
		int in;
		scanf("%d", &in);
		if (in == 0)
			break;
		arr.push_back(in);
	}
	memset(cache, -1, sizeof(cache));
	printf("%d\n", search(0, 0, 0));
	return 0;
}