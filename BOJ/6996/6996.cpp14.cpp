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
int N;
int cnt[26];
bool possi() {
	for (int i = 0; i < 26; i++)
		if (cnt[i] != 0)
			return false;
	return true;
}
int main(){
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		memset(cnt, 0, sizeof(cnt));
		string A, B;
		cin >> A >> B;
		for (int j = 0; j < A.size(); j++)
			cnt[A[j] - 'a']++;
		for (int j = 0; j < B.size(); j++)
			cnt[B[j] - 'a']--;
		cout << A << " & " << B << " are ";
		printf("%sanagrams.\n", !possi() ? "NOT " : "");
	}
	return 0;
}