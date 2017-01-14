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
#define INF 0x3f3f3f3f
#define UINF 0xffffffffu
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int arr[100];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int M;
	cin >> M;
	int cnt = 0;
	for (int i = 0; i < N; i++)
		if (arr[i] == M)
			cnt++;
	printf("%d\n", cnt);
	return 0;
}