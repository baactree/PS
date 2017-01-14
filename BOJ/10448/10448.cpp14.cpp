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
#define all(x) x.begin(),x.end()
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
vector<int> arr;
int cache[45][1001][4];
int solve(int idx, int num,int cnt) {
	if (idx == arr.size()) {
		if(num==0&&cnt==0)
			return 1;
		return 0;
	}
	if (num < 0||cnt<0)
		return 0;
	int &ret = cache[idx][num][cnt];
	if (ret != -1)
		return ret;
	ret = solve(idx + 1, num, cnt);
	ret |= solve(idx , num - arr[idx], cnt - 1);
	return ret;
}
int main() {
	for (int i = 1; i*(i + 1) / 2 <= 1000; i++) 
		arr.push_back(i*(i + 1) / 2);
	int Case;
	cin >> Case;
	memset(cache, -1, sizeof(cache));
	while (Case--) {
		int N;
		scanf("%d", &N);
		printf("%d\n", solve(0, N, 3));
	}
	return 0;
}
