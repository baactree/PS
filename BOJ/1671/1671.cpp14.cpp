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
struct node {
	int a, b, c;
	const bool operator <= (const node &rhs) const{
		return a <= rhs.a&&b <= rhs.b&&c <= rhs.c;
	}
	const bool operator == (const node &rhs) const{
		return a == rhs.a&&b == rhs.b&&c == rhs.c;
	}
};
int N;
vector<node> arr(1000);
bool trip[1000];
int matched[1000];
vector<int> adj[1000];
bool dfs(int v) {
	if (trip[v])
		return false;
	trip[v] = true;
	for (auto there : adj[v]) {
		if (matched[there] == -1 || dfs(matched[there])) {
			matched[there] = v;
			return true;
		}
	}
	return false;
}
int main() {
	memset(matched, -1, sizeof(matched));
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i] <= arr[j]) {
				if (arr[i] == arr[j] && i <= j)
					continue;
				adj[j].push_back(i);
			}
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2; j++) {
			memset(trip, 0, sizeof(trip));
			if (dfs(i))
				ans++;
		}
	printf("%d\n", N - ans);
	return 0;
}