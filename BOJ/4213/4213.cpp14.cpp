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
int N;
int cache[2501][51];
int b[51];
vector<pair<int, int> > dish;
int solve(int idx,int front) {
	if (idx == dish.size())
		return 0;
	int &ret = cache[idx][front];
	if (ret != -1)
		return ret;
	ret = INF;
	int now = dish[idx].first;
	int st, fi;
	st = fi = idx;
	while (fi + 1 < dish.size() && dish[fi].first == dish[fi + 1].first)
		fi++;
	int cnt = 0;
	bool flag = false;
	int fidx;
	for (int i = st; i <= fi; i++) {
		if (b[dish[i].second] != now)
			cnt++;
		if (dish[i].second == front) {
			fidx = i;
			flag = true;
		}
	}
	if (flag) {
		//front에서 이어서 만드는 방법이 존재함
		for (int i = st; i <= fi; i++) {
			if (st!=fi&&i == fidx)
				continue;
			ret = min(ret, solve(fi + 1, dish[i].second) + fi - st + cnt - 1);
		}
	}
	for (int i = st; i <= fi; i++) 
		ret = min(ret, solve(fi + 1, dish[i].second) + fi - st + 1 + cnt);
	return ret;
}
int main() {
	int cnt = 0;
	while (scanf("%d", &N) != EOF) {
		cnt++;
		memset(b, -1, sizeof(b));
		dish.clear();
		for (int i = 0; i < N; i++) {
			int h;
			scanf("%d", &h);
			while (h--) {
				int r;
				scanf("%d", &r);
				dish.push_back({ r,i });
				b[i] = max(b[i], r);
			}
		}
		sort(dish.begin(), dish.end());
		dish.erase(unique(dish.begin(), dish.end()), dish.end());
		memset(cache, -1, sizeof(cache));
		printf("Case %d: %d\n", cnt,solve(0,50)-1);
	}
	return 0;
}
