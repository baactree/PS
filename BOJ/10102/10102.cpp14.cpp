/////////////////////////////////////////////////////
#include "bits/stdc++.h"
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
int a, b;
int main() {
	int n;
	string str;
	cin >> n >> str;
	
	for (int i = 0; i < n; i++)
		if (str[i] == 'A')
			a++;
		else
			b++;
	if (a > b)
		printf("A\n");
	else if (a < b)
		printf("B\n");
	else
		cout << "Tie\n";
	return 0;
}