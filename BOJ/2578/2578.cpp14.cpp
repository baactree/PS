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
int mat[5][5];
void del(int in) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (mat[i][j] == in)
				mat[i][j] = 0;
}
bool finish() {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		bool flag = true;
		for (int j = 0; j < 5; j++)
			if (mat[i][j] != 0)
				flag = false;
		if (flag)
			cnt++;
	}
	for (int i = 0; i < 5; i++) {
		bool flag = true;
		for (int j = 0; j < 5; j++)
			if (mat[j][i] != 0)
				flag = false;
		if (flag)
			cnt++;
	}
	bool flag = true;
	for (int i = 0; i < 5; i++)
		if (mat[i][i] != 0)
			flag = false;
	if (flag)
		cnt++;
	flag = true;
	for (int i = 0; i < 5; i++)
		if (mat[i][4 - i] != 0)
			flag = false;
	if (flag)
		cnt++;
	return cnt >= 3;
}
int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &mat[i][j]);
	for (int i = 0; i < 25; i++) {
		int in;
		scanf("%d", &in);
		del(in);
		if (finish()) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	return 0;
}