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
	char input[20];
	int N;
	while (scanf("%s%d", input, &N) != EOF) {
		N--;
		char temp[20];
		memcpy(temp, input, sizeof(temp));
		int len = strlen(input);
		int cnt = 0;
		do {
			if (cnt == N)
				break;
			cnt++;
		} while (next_permutation(input, input + len));
		printf("%s %d = %s\n", temp, N + 1,cnt==N?input:"No permutation");
	}
	return 0;
}