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
struct Node {
	int x, y, n;
};
int R, C;
int mat[300][300];
int main(){
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			scanf("%1d", &mat[i][j]);
	queue<Node> even;
	int ans = -1;
	for (int i = 0; i < R - 1; i++)
		for (int j = 0; j < C - 1; j++) 
			if (mat[i][j] == mat[i + 1][j + 1] && mat[i + 1][j] == mat[i][j + 1])
				even.push({ i,j,2 });
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			even.push({ i,j,1 });
	while (!even.empty()) {
		int nx = even.front().x;
		int ny = even.front().y;
		int nn = even.front().n;
		even.pop();
		ans = max(ans, nn);
		nn += 2;
		nx--; ny--;
		if (nx < 0 || ny < 0 || nx + nn > R || ny + nn > C)
			continue;
		bool flag = true;
		for (int i = 0; i < nn; i++) {
			if (mat[nx][ny+i]!=mat[nx+nn-1][ny+nn-1-i]) {
				flag = false;
				break;
			}
			if (mat[nx+i][ny]!=mat[nx+nn-1-i][ny+nn-1]) {
				flag = false;
				break;
			}
		}
		if (flag)
			even.push({ nx ,ny ,nn });
	}
	printf("%d\n", ans);
	return 0;
}