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
char input[1000001];
vector<int> get_pi() {
	int n = strlen(input);
	vector<int> pi(n);
	int begin = 1, matched = 0;
	while (begin + matched < n) {
		if (input[begin + matched] == input[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin = begin + matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}
int rpi[1000000];
int main() {
	int N;
	scanf("%d%s", &N, input);
	vector<int> pi = get_pi();
	ll sum = 0;
	memset(rpi, -1, sizeof(rpi));
	for (int i = 0; i < N; i++) {
		if (pi[i]) {
			int now = pi[i];
			while (rpi[now-1]==-1&&pi[now-1] != 0)
				now = pi[now-1];
			if (rpi[now-1] != -1)
				now = rpi[now-1];
			rpi[i] = now;
			sum += (i + 1 - now);
		}
	}
	cout << sum << endl;
	return 0;
}