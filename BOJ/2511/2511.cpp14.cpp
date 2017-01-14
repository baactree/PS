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
	int a, b;
	bool flag = false;
	bool ff = false;
	a = b = 0;
	vector<int> A(10);
	vector<int> B(10);
	for (int i = 0; i < 10; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < 10; i++)
		scanf("%d", &B[i]);
	for (int i = 0; i < 10; i++)
		if (A[i] > B[i])
			a += 3, flag = true, ff = true;
		else if (B[i] > A[i])
			b += 3, flag = true, ff = false;
		else
			a++, b++;
	printf("%d %d\n", a, b);
	if (flag) {
		if (a > b)
			printf("A\n");
		else if (b > a)
			printf("B\n");
		else
			printf("%s", ff? "A\n" : "B\n");
	}
	else
		printf("D\n");
	return 0;
}