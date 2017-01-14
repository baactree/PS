/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
#define INF 0x3f3f3f3f
#define UINF 0xffffffffu
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int cnt[5];
string str[5] = { "Q1: ","Q2: ","Q3: ","Q4: ","AXIS: " };
int main() {
	while (true) {
		int N;
		cin >> N;
		if (N == -1)
			break;
		vector<int> factor;
		int sum = 0;
		for (int i = 1; i*i <= N; i++) {
			if (N%i == 0) {
				sum += i;
				sum += N / i;
				factor.push_back(i);
				factor.push_back(N / i);
			}
			if (i*i == N) {
				sum -= i;
				factor.pop_back();
			}
		}
		sum -= N;
		if (sum != N) {
			printf("%d is NOT perfect.\n", N);
			continue;
		}
		sort(factor.begin(), factor.end());
		factor.pop_back();
		printf("%d = %d", N, factor[0]);
		for (int i = 1; i < factor.size(); i++)
			printf(" + %d", factor[i]);
		printf("\n");
	}
	return 0;
}