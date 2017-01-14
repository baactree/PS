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
struct Node {
	int x1, x2, y1, y2;
	Node (int x1,int y1,int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2){}
};
int N;
int mat[51][51];
vector<Node> arr[5000001];
const int shift = 2500000;
int sum[51][51];
extern inline int calc(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &mat[i][j]);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			sum[i][j] = sum[i][j - 1] + mat[i][j];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			sum[i][j] += sum[i - 1][j];
	for(int x1=0;x1<N;x1++)
		for(int y1=0;y1<N;y1++)
			for(int x2=x1+1;x2<=N;x2++)
				for (int y2 = y1 + 1; y2 <= N; y2++) {
					arr[calc(x1, y1, x2, y2) + shift].push_back({ x1,y1,x2,y2 });
				}
	int ans = 0;
	int temp[51][51];
	for (int i = 0; i < 5000001; i++) {
		if (arr[i].size() > 1) {
			memset(temp, 0, sizeof(temp));
			for (int j = 0; j < arr[i].size(); j++)
				temp[arr[i][j].x1][arr[i][j].y1]++;
			for (int j = 0; j < arr[i].size(); j++) {
				ans += temp[arr[i][j].x2][arr[i][j].y2];
			}
			memset(temp, 0, sizeof(temp));
			for (int j = 0; j < arr[i].size(); j++)
				temp[arr[i][j].x1][arr[i][j].y2]++;
			for (int j = 0; j < arr[i].size(); j++)
				ans += temp[arr[i][j].x2][arr[i][j].y1];
		}
	}
	printf("%d\n", ans);
	return 0;
}