/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
ll arr[100];
priority_queue<ll> pq;
queue<ll> q;
set<ll> s;
int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) 
		scanf("%lld", &arr[i]);
	q.push(1);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			ll now = q.front();
			q.pop();
			for (int j = 0; j < N; j++) {
				long long value = arr[j] * now;
				if (value <= 0xffffffffll) {
					if (pq.size() < K) {
						if (s.insert(value).second) {
							pq.push(value);
							q.push(value);
						}
					}
					else {
						if (pq.top() > value) {
							if (s.insert(value).second) {
								pq.pop();
								pq.push(value);
								q.push(value);
							}
						}
					}
				}
			}
		}
	}
	printf("%lld\n", pq.top());
	return 0;
}