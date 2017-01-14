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
struct Node {
	int s[4];
	int score;
	int idx;
	Node() {
		s[1] = s[2] = s[3] = score = 0;
	}
	bool operator < (const Node& rhs)const {
		if (score == rhs.score) {
			if (s[3] == rhs.s[3]) {
				return s[2] > rhs.s[2];
			}
			return s[3] > rhs.s[3];
		}
		return score > rhs.score;
	}
};
int N;
Node arr[4];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= 3; j++) {
			int in;
			scanf("%d", &in);
			arr[j].s[in]++;
			arr[j].score += in;
			arr[j].idx = j;
		}
	}
	sort(arr + 1, arr + 4);
	if (arr[1].score == arr[2].score&&arr[1].s[3] == arr[2].s[3]
		&& arr[1].s[2] && arr[2].s[2]) {
		printf("0 %d\n", arr[1].score);
	}
	else
		printf("%d %d\n", arr[1].idx, arr[1].score);
	return 0;
}