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
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		int idx;
		int cnt = 0;
		for (int i = 0; i < str.size(); i++)
			if (str[i] == ' ') {
				cnt++;
				if (cnt == 2)
					idx = i;
			}
		for (int i = idx + 1; i < str.size(); i++)
			printf("%c", str[i]);
		printf(" ");
		for (int i = 0; i < idx; i++)
			printf("%c", str[i]);
		printf("\n");
	}
	return 0;
}