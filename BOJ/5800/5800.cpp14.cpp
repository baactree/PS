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
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int main() {
	int tc;
	cin >> tc;
	for (int Tc = 1; Tc <= tc;Tc++){
		int N;
		scanf("%d", &N);
		vector<int> arr(N);
		int gap = 0;
		for (int i = 0; i < N; i++) 
			scanf("%d", &arr[i]);
		sort(arr.begin(), arr.end());
		for (int i = 1; i < N; i++)
			gap = max(gap, arr[i] - arr[i - 1]);
		printf("Class %d\nMax %d, Min %d, Largest gap %d\n", Tc, arr[N - 1], arr[0], gap);
	}
	return 0;
}