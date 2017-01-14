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
int cnt[5];
string str[5] = { "Q1: ","Q2: ","Q3: ","Q4: ","AXIS: " };
int main() {
	int N;
	pair<int, int> in;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> in.first >> in.second;
		if (in.first == 0 || in.second == 0)
			cnt[4]++;
		else if (in.first > 0) {
			if (in.second > 0)
				cnt[0]++;
			else
				cnt[3]++;
		}
		else {
			if (in.second > 0)
				cnt[1]++;
			else
				cnt[2]++;
		}
	}
	for (int i = 0; i < 5; i++)
		cout << str[i] << cnt[i] << endl;
	return 0;
}