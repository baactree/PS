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
int main(){
	int arr[3];
	char str[4];
	scanf("%d%d%d%s", &arr[0], &arr[1], &arr[2], str);
	sort(arr, arr + 3);
	for (int i = 0; i < 3; i++)
		if (str[i] == 'A')
			printf("%d ", arr[0]);	
		else if (str[i] == 'B')
			printf("%d ", arr[1]);
		else
			printf("%d ", arr[2]);
	return 0;
}