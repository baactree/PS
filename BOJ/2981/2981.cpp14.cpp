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
vector<int> ans;
int arr[100];
vector<int> diff;
int N;
vector<int> factor;
bool possi(int num) {
	int k = arr[0] % num;
	for (int i = 0; i < N; i++)
		if (k != arr[i] % num)
			return false;
	return true;
}
int main() {
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	for (int i = 1; i < N; i++) 
		diff.push_back(arr[i] - arr[i - 1]);
	sort(diff.begin(), diff.end());
	int num = diff[0];
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0) {
			factor.push_back(i);
			if (i*i != num)
				factor.push_back(num / i);
		}
	}
	factor.push_back(num);
	sort(factor.begin(), factor.end());
	for (auto i : factor) {
		if (possi(i))
			ans.push_back(i);
	}
	for (auto i : ans)
		printf("%d ", i);
	cout << endl;
	return 0;
}