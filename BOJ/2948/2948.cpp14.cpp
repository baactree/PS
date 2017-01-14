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
string str[7] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	int M, D;
	scanf("%d%d", &D, &M);
	int day = D + 2;
	for (int i = 0; i < M; i++)
		day += month[i];
	cout << str[day % 7] << endl;
	return 0;
}
