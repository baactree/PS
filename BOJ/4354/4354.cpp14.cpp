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
int main() {
	while (true) {
		scanf("%s", input);
		if (input[0] == '.')
			break;
		int len = strlen(input);
		vector<int> pi = get_pi();
		printf("%d\n", len / (len - pi[len - 1]));
	}
	return 0;
}