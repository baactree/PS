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
int mat[200][100];
int main(){
	scanf("%d", &N);
	if (N == 1)
		printf("*\n");
	else {
		for (int i = 0; i < N * 2; i++) {
			for (int j = 0; j < N; j++)
				printf("%s", (i + j) & 1 ? " " : "*");
			printf("\n");
		}
	}
	return 0;
}