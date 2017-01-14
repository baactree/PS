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
int sh, sm, ss;
int fh, fm, fs;
int main() {
	scanf("%d:%d:%d", &sh, &sm, &ss);
	scanf("%d:%d:%d", &fh, &fm, &fs);
	if (sh == fh&&sm == fm&&ss == fs) {
		printf("24:00:00\n");
		return 0;
	}
	fh += 24;
	fs -= ss;
	if (fs < 0) {
		fs += 60;
		fm--;
	}
	fm -= sm;
	if (fm < 0) {
		fm += 60;
		fh--;
	}
	fh -= sh;
	fh %= 24;
	printf("%02d:%02d:%02d\n", fh, fm, fs);
	return 0;
}