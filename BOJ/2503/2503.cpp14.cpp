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
struct Node {
	int  b, c;
	string a;
};
int N;
Node arr[100];
bool possi(string str) {
	for (int i = 0; i < N; i++) {
		int st = 0;
		int ba = 0;
		for (int j = 0; j < 3; j++)
			if (str[j] == arr[i].a[j])
				st++;
		if (arr[i].a[0] == str[1] || arr[i].a[0] == str[2])
			ba++;
		if (arr[i].a[1] == str[0] || arr[i].a[1] == str[2])
			ba++;
		if (arr[i].a[2] == str[1] || arr[i].a[2] == str[0])
			ba++;
		if (st != arr[i].b || ba != arr[i].c)
			return false;
	}
	return true;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i == j)
				continue;
			for (int k = 1; k <= 9; k++) {
				if (k == i || k == j)
					continue;
				string num = to_string(i) + to_string(j) + to_string(k);
				if (possi(num))
					ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}