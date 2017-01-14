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
string temp[8] = { "000","001","010","011","100","101","110","111" };
int main() {
	string str;
	cin >> str;
	int len = str.size();
	string tt = "";
	for (int i = 0; i < (3 - len % 3) % 3; i++)
		tt += "0";
	tt += str;
	for (int i = 0; i < tt.size(); i += 3)
		for (int j = 0; j < 8; j++)
			if (temp[j] == string(tt.begin() + i, tt.begin() + i + 3))
				printf("%d", j);
	printf("\n");
	return 0;
}