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
	int arr[3];
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	if (sum != 180) {
		printf("Error\n");
		return 0;
	}
	sort(arr, arr + 3);
	if (arr[2] == 60) {
		printf("Equilateral\n");
		return 0;
	}
	if (arr[0] == arr[1] || arr[1] == arr[2]) {
		printf("Isosceles\n");
		return 0;
	}
	printf("Scalene\n");
	return 0;
}