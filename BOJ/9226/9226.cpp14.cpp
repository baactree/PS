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
char vowel[5] = { 'a','e','i','o','u' };
extern inline bool is_vowel(char c) {
	for (int i = 0; i < 5; i++)
		if (c == vowel[i])
			return true;
	return false;
}
int main() {
	while (true) {
		string str;
		cin >> str;
		if (str == "#")
			break;
		int idx = 0;
		for (int i = 0; i < str.size(); i++)
			if (is_vowel(str[i])) {
				idx = i;
				break;
			}
		string ans = "";
		for (int i = idx; i < str.size(); i++)
			ans += str[i];
		for (int i = 0; i < idx; i++)
			ans += str[i];
		ans += "ay\n";
		cout << ans;
	}
	return 0;
}