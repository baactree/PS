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

int main() {
	int N;
	scanf("%d", &N);
	vector<int> cnt(26, 0);
	for (int i = 0; i < N; i++) {
		string arr;
		cin >> arr;
		cnt[arr[0] - 'a']++;
	}
	bool flag = false;
	for (int i = 0; i < 26; i++)
		if (cnt[i] >= 5)
			printf("%c", i + 'a'), flag = true;
	if (!flag)
		printf("PREDAJA");
	printf("\n");
	return 0;
}