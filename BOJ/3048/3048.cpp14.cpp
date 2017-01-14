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
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
string a, b;
string output;
vector<bool> mark;
int n, m;
void calc() {
	for (int i = 0; i < n + m - 1; i++) {
		if (mark[i]) {
			if (!mark[i + 1]) {
				swap(output[i], output[i + 1]);
				swap(mark[i], mark[i + 1]);
				i++;
			}
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	cin >> a >> b;
	reverse(a.begin(), a.end());
	output = a + b;
	int t;
	scanf("%d", &t);
	mark = vector<bool>(n + m, 0);
	for (int i = 0; i < n; i++)
		mark[i] = true;
	for (int i = 0; i < t; i++)
		calc();
	cout << output << endl;
	return 0;
}