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
char input[10005];
vector<int> inde;
int main() {
	int idx = 0;
	while (scanf("%s", input + idx)!=EOF) {
		idx = strlen(input);
	}
	int cnt = 0;
	inde.push_back(0);
	for (int i = 0; i < idx; i++)
		if (input[i] == ',')
			cnt++, inde.push_back(i + 1);
	ll sum = 0;
	int in;
	for (int i = 0; i <= cnt; i++) {
		sscanf(input+inde[i], "%d",&in);
		sum += in;
	}
	printf("%lld\n", sum);
	return 0;
}