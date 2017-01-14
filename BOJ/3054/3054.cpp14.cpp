/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
char out[5][15 * 10];
char in[16];
void mark(int idx, int k) {
	for (int i = 0; i < 5;i++) {
		for (int j = idx - 2; j <= idx + 2; j++) {
			out[i][j] = '.';
		}
	}
	out[2][idx] = in[k];
	out[2][idx - 2] = out[2][idx + 2] = '#';
	out[1][idx - 1] = out[1][idx + 1] = '#';
	out[0][idx] = '#';
	out[4][idx] = '#';
	out[3][idx - 1] = out[3][idx + 1] = '#';
}
void remark(int idx, int k) {
	out[2][idx - 2] = out[2][idx + 2] = '*';
	out[1][idx - 1] = out[1][idx + 1] = '*';
	out[0][idx] = '*';
	out[4][idx] = '*';
	out[3][idx - 1] = out[3][idx + 1] = '*';
}
int main() {
	scanf("%s", in);
	int len = strlen(in);
	int idx = 2;
	for (int i = 0; i < len; i++) {
		mark(idx, i);
		idx += 4;
	}
	idx = 2;
	for (int i = 0; i < len; i++) {
		if ((i + 1) % 3 == 0)
			remark(idx, i);
		idx += 4;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < len * 5 - len + 1; j++)
			printf("%c", out[i][j]);
		printf("\n");
	}
	return 0;
}