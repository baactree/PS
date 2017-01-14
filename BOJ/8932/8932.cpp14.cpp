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
double A[7] = { 9.23076,1.84523,56.0211,4.99087,0.188807,15.9803,0.11193 };
double B[7] = { 26.7,75,1.5,42.5,210,3.8,254 };
double C[7] = { 1.835,1.348,1.05,1.81,1.41,1.04,1.88 };
bool T[7] = { 0,1,1,0,1,1,0 };
int P[7];
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		for (int i = 0; i < 7; i++)
			scanf("%d", &P[i]);
		int ans = 0;
		for (int i = 0; i < 7; i++) {
			if (!T[i])
				ans += (int)(A[i] * pow(B[i] - P[i], C[i]));
			else
				ans += (int)(A[i] * pow(P[i] - B[i], C[i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}