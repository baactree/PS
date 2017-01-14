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
typedef unsigned int lu;
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
char dna[1000001];
char mark[101];
llu p;
const llu k = 255;
unordered_set<llu> s;
extern inline void hashing(const string& str) {
	llu H = 0;
	for (int i = 0; i < M; i++)
		H = H*k + str[i]-'0';
	s.insert(H);
}
int solve() {
	int ret = 0;
	llu H = 0;
	for (int i = 0; i + M < N + 1; i++) {
		if (i == 0) {
			for (int j = 0; j < M; j++)
				H = H*k + dna[j]-'0';
		}
		else {
			H = (H - (dna[i - 1]-'0') * p)*k + dna[i + M - 1]-'0';
		}
		if (s.count(H) != 0)
			ret++;
	}
	return ret;
}
int main() {
	int Case;
	scanf("%d", &Case);
	while (Case--) {
		s.clear();
		scanf("%d%d", &N, &M);
		scanf("%s%s", dna, mark);
		for (int i = 0; i < N; i++) {
			if (dna[i] == 'A')
				dna[i] = '0';
			else if (dna[i] == 'G')
				dna[i] = '1';
			else if (dna[i] == 'T')
				dna[i] = '2';
			else if (dna[i] == 'C')
				dna[i] = '3';
		}
		for (int i = 0; i < M; i++) {
			if (mark[i] == 'A')
				mark[i] = '0';
			else if (mark[i] == 'G')
				mark[i] = '1';
			else if (mark[i] == 'T')
				mark[i] = '2';
			else if (mark[i] == 'C')
				mark[i] = '3';
		}
		p = 1;
		for (int i = 1; i < M; i++)
			p *= k;
		for (int i = 0; i <= M; i++)
			for (int j = i; j <= M; j++) {
				string temp = mark;
				reverse(temp.begin() + i, temp.begin() + j);
				hashing(temp);
			}
		printf("%d\n", solve());
	}
	return 0;
}