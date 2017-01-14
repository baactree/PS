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

int main(void){
	int N, M;
	set<int> s;
	scanf("%d%d", &N, &M);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int in;
		scanf("%d", &in);
		if (s.find(M - in) != s.end())
			ans++;
		s.insert(in);
	}
	printf("%d\n", ans);
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}