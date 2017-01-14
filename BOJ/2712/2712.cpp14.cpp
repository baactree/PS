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
	cin >> N;
	for (int i = 0; i < N; i++) {
		double input;
		string str;
		cin >> input >> str;
		if (str == "kg") {
			printf("%.4lf lb\n", 2.2046*input);
		}
		else if (str == "l") {
			printf("%.4lf g\n", 0.2642*input);
		}
		else if (str == "lb") {
			printf("%.4lf kg\n", 0.4536*input);
		}
		else {
			printf("%.4lf l\n", 3.7854*input);
		}
	}
	return 0;
}