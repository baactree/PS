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
int N;
int arr[50];
bool mat[50][50];
int matched[50];
bool trip[50];
bool prime(int num) {
	if (num <= 1)
		return false;
	if (num == 2)
		return true;
	for (int i = 2; i*i <= num; i++)
		if (num%i == 0)
			return false;
	return true;
}
int sz;
bool dfs(int v) {
	if (trip[v])
		return false;
	trip[v] = true;
	for (int i = 0; i < sz;i++)
		if(mat[v][i])
			if (matched[i] == -1 || dfs(matched[i])) {
				matched[i] = v;
				return true;
			}
	return false;
}
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	vector<int> ans;
	for (int k = 1; k < N; k++) {
		if (prime(arr[0] + arr[k])) {
			memset(mat, 0, sizeof(mat));
			vector<int> even;
			vector<int> odd;
			for (int i = 1; i < N; i++) {
				if (k == i)continue;
				if (arr[i] & 1)
					odd.push_back(i);
				else
					even.push_back(i);
			}
			for (int i = 0; i < odd.size(); i++)
				for (int j = 0; j < even.size(); j++)
					if (prime(arr[odd[i]] + arr[even[j]]))
						mat[i][j] = true;
			memset(matched, -1, sizeof(matched));
			sz = even.size();
			int cnt = 0;
			for (int i = 0; i < odd.size(); i++) {
				memset(trip, 0, sizeof(trip));
				if (dfs(i))
					cnt++;
			}
			if (cnt * 2 >= N - 2)
				ans.push_back(arr[k]);
		}
	}
	if (ans.empty())
		printf("-1\n");
	else {
		sort(ans.begin(), ans.end());
		for (auto i : ans)
			printf("%d ", i);
		printf("\n");
	}
	return 0;
}