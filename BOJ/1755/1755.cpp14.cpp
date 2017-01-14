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
string num[10] = { "zero","one","two","tree","four","five","six","seven","eight","nine" };
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	if (N > M)
		swap(N, M);
	vector<pair<string,int> > ans;
	for (int i = N; i <= M; i++){
		string now = "";
		int temp = i;
		if (temp >= 10) {
			now += num[temp / 10];
			temp %= 10;
		}
		now += num[temp];
		ans.push_back({ now, i });
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i].second);
		if (i % 10 == 9)
			printf("\n");
		else if (i != ans.size() - 1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}