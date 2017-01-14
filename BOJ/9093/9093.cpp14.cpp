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
	int tc;
	scanf("%d\n", &tc);
	vector<char> arr;
	char temp;
	while (scanf("%c", &temp)!= EOF) {
		if (temp == ' ') {
			reverse(all(arr));
			for (auto i : arr)
				printf("%c", i);
			printf(" ");
			arr.clear();
		}
		else if (temp == '\n') {
			reverse(all(arr));
			for (auto i : arr)
				printf("%c", i);
			printf("\n");
			arr.clear();
		}
		else
			arr.push_back(temp);
	}
	return 0;
}