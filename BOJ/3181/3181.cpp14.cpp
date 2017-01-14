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
string str[10] = { "i","pa","te","ni","niti","a","ali","nego","no","ili" };
bool contin(const string &now) {
	for (int i = 0; i < 10; i++)
		if (now == str[i])
			return true;
	return false;
}
int main() {
	char input[110];
	string ans = "";
	bool first = true;
	while (scanf("%s", input) != EOF) {
		string now = input;
		if (!first&&contin(now)) 
			continue;
		ans += now[0] - 'a' + 'A';
		first = false;
	}
	cout << ans << endl;
	return 0;
}