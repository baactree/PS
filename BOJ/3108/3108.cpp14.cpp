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
struct R {
	int x1, x2, y1, y2;
};
int N;
R arr[1001];
vector<int> edge[1001];
bool trip[1001];
void dfs(int n) {
	if (trip[n])
		return;
	trip[n] = true;
	for (int i = 0; i < edge[n].size(); i++)
		dfs(edge[n][i]);
	return;
}
extern inline bool cross(int a, int b) {
	if (arr[a].x2 < arr[b].x1 || arr[b].x2 < arr[a].x1)
		return false;
	if (arr[a].y2 < arr[b].y1 || arr[b].y2 < arr[a].y1)
		return false;
	if (arr[a].x1 < arr[b].x1&&arr[b].x2 < arr[a].x2&&
		arr[a].y1 < arr[b].y1&&arr[b].y2 < arr[a].y2)
		return false;
	if (arr[b].x1 < arr[a].x1&&arr[a].x2 < arr[b].x2&&
		arr[b].y1 < arr[a].y1&&arr[a].y2 < arr[b].y2)
		return false;
	return true;
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) 
		scanf("%d%d%d%d", &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
	for (int i = 0; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (cross(i, j)) {
				edge[i].push_back(j);
                edge[j].push_back(i);
            }
		}
	}
	int ans = 0;
	dfs(0);
	for (int i = 1; i <= N; i++)
		if (!trip[i]) {
			dfs(i);
			ans++;
		}
	printf("%d\n", ans);
	return 0;
}