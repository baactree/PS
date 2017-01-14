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
struct Node {
	ll x, y, cnt;
	Node():x(0),y(0),cnt(0){}
	Node(int x,int y,ll cnt):x(x),y(y),cnt(cnt){}
};
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
Node front[5];
Node now[5];
int main(){
	int N;
	scanf("%d", &N);
	int x, y;
	scanf("%d%d", &x, &y);
	front[0] = Node(x, y, 0);
	for (int i = 0; i < 4; i++)
		front[i + 1] = front[0];
	while (N--) {
		scanf("%d%d", &x, &y);
		now[0] = Node(x, y, LINF);
		for (int i = 0; i < 4; i++) {
			now[i + 1].x = x + dx[i];
			now[i + 1].y = y + dy[i];
			now[i + 1].cnt = LINF;
		}
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				int dist = abs(front[i].x - now[j].x) + abs(front[i].y - now[j].y);
				now[j].cnt = min(now[j].cnt, front[i].cnt + dist);
			}
		for (int i = 0; i < 5; i++)
			front[i] = now[i];
	}
	vector<ll> ans;
	for (int i = 0; i < 5; i++)
		ans.push_back(front[i].cnt);
	printf("%lld\n", *min_element(ans.begin(), ans.end()));
	return 0;
}