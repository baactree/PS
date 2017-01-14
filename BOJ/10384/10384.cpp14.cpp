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
	int cs;
	scanf("%d\n", &cs);
	for (int tc = 1; tc <= cs; tc++) {
		string str;
		getline(cin, str);
		vector<int> cnt(26, 0);
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= 'A'&&str[i] <= 'Z')
				str[i] = str[i] - 'A' + 'a';
			if (str[i] >= 'a'&&str[i] <= 'z')
				cnt[str[i] - 'a']++;
		}
		int min_value = *min_element(cnt.begin(), cnt.end());
		if (min_value == 0)
			printf("Case %d: Not a pangram\n",tc);
		if (min_value == 1)
			printf("Case %d: Pangram!\n",tc);
		if (min_value == 2)
			printf("Case %d: Double pangram!!\n",tc);
		if (min_value >= 3)
			printf("Case %d: Triple pangram!!!\n",tc);
	}
	return 0;
}