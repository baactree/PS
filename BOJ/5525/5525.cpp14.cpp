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
int N, M;
string str;
vector<int> get_pi(const string& str) {
	int n = str.size();
	vector<int> pi(n, 0);
	int begin = 1, matched = 0;
	while (begin + matched < n) {
		if (str[begin + matched] == str[matched]) {
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
int kmp(const string &S, const string &H) {
	int n = S.size();
	int m = H.size();
	vector<int> pi = get_pi(H);
	int begin, matched;
	begin = matched = 0;
	int ret = 0;
	while (begin + matched < n) {
		if (matched<m&&S[begin + matched] == H[matched]) {
			matched++;
			if (matched == m) {
				ret++;
			}
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
	return ret;
}
int main() {
	cin >> N >> M >> str;
	string H = "";
	for (int i = 0; i < N; i++)
		H += "IO";
	H += "I";
	printf("%d\n", kmp(str, H));
	return 0;
}