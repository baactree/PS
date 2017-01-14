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

int main() {
	string a, b, c;
	cin >> a >> c >> b;
	string output;
	if (a < b)
		swap(a, b);
	if (c == "*") {
		int la = a.length();
		int lb = b.length();
		output = "1";
		for (int i = 0; i < la + lb - 2; i++)
			output += "0";
	}
	else {
		int la = a.length();
		int lb = b.length();
		output = a;
		if (output[la - lb] == '1')
			output[la - lb] = '2';
		else
			output[la - lb] = '1';
	}
	cout << output << endl;
	return 0;
}