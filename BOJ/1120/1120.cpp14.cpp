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
string A, B;
int main(){
	cin >> A >> B;
	int ans = INF;
	for (int i = 0; i + A.size() <= B.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < A.size(); j++)
			if (B[i+j] != A[j])
				cnt++;
		ans = min(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}