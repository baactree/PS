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
int g[6] = { 1,2,3,3,4,10 };
int s[7] = { 1,2,2,2,3,5,10 };
int G, S;
int main() {
	int Case;
	cin >> Case;
	for(int t=1;t<=Case;t++) {
		G = S = 0;
		for (int i = 0; i < 6; i++) {
			int in;
			scanf("%d", &in);
			G += g[i] * in;
		}
		for (int i = 0; i < 7; i++) {
			int in;
			scanf("%d", &in);
			S += s[i] * in;
		}
		printf("Battle %d: ", t);
		if (G > S)
			cout << "Good triumphs over Evil" << endl;
		else if (S > G)
			cout << "Evil eradicates all trace of Good" << endl;
		else
			cout << "No victor on this battle field" << endl;
	}
	return 0;
}