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
int N;
int arr[100000];
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	vector<int> t;
	for (int i = 0; i < N - 1; i++)
		t.push_back(arr[i + 1] - arr[i]);
	int d;
	d = t[0];
	for (int i = 0; i + 1< t.size(); i++)
		d = gcd(d, t[i + 1]);
	int ans = (arr[N - 1] - arr[0]) / d + 1 - N;
	
	printf("%d\n", ans);
	return 0;
}