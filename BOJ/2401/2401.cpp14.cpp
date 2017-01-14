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
string N;
string L;
vector<int> arr[100000];
int cache[100000];
vector<int> get_pi(string &B) {
	int m = B.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (B[begin + matched] == B[matched]) {
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
void get_kmp(string &A, string &B) {
	int n = A.size();
	int m = B.size();
	vector<int> pi = get_pi(B);
	int begin = 0, matched = 0;
	while (begin <= n - m) {
		if (matched < m&&A[begin + matched] == B[matched]) {
			matched++;
			if (matched == m)
				arr[begin].push_back(m);
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
	return;
}
int solve(int idx) {
	if (idx == N.size())
		return 0;
	int &ret = cache[idx];
	if (ret != -1)
		return ret;
	ret = solve(idx + 1);
	for (int i = 0; i < arr[idx].size(); i++) 
		ret = max(ret, solve(arr[idx][i] + idx) + arr[idx][i]);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> L;
		get_kmp(N, L);
	}
	printf("%d\n", solve(0));
	return 0;
}