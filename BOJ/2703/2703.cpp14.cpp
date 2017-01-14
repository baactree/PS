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
int trans[26];
int main() {
	int Case;
	scanf("%d\n", &Case);
	while (Case--) {
		string in;
		getline(cin, in);
		string alpa;
		getline(cin, alpa);
		for (int i = 0; i < alpa.size(); i++)
			trans[i] = alpa[i]-'A';
		for (int i = 0; i < in.size(); i++) {
			if (in[i] >= 'A'&&in[i] <= 'Z')
				in[i] = trans[in[i] - 'A'] + 'A';
		}
		cout << in << endl;
	}
	return 0;
}