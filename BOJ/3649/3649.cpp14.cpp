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
int arr[1000000];
int main() {
	int N, X;
	while (scanf("%d%d",&X,&N)!=EOF) {
		X *= 10000000;
		set<int> s;
		pii ans=make_pair(0,0);
		bool flag = false;
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + N);
		for (int i = 0; i < N; i++) {
			if (binary_search(arr + 1 + i, arr + N, X - arr[i])) {
				flag = true;
                //if(abs(ans.first-ans.second)<abs(X-2*arr[i]))
				    ans = make_pair(arr[i], X - arr[i]);
				break;
			}
		}
		if (flag)
			printf("yes %d %d\n", ans.first, ans.second);
		else
			printf("danger\n");
	}
	return 0;
}