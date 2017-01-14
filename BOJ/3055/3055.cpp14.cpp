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
char mat[50][51];
int R, C;
struct Node {
	int x, y, cnt;
	Node(int x,int y,int cnt):x(x),y(y),cnt(cnt){}
};
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool safe(int x, int y) {
	return (x >= 0 && x < R&&y >= 0 && y < C);
}
int main(){
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++)
		scanf("%s", mat[i]);
	queue<Node> water;
	queue<Node> me;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (mat[i][j] == '*')
				water.push({ i,j,0 });
			else if (mat[i][j] == 'S')
				me.push({ i,j,0 });
	int ans=-1;
	while (!me.empty()) {
		int size = water.size();
		for (int i = 0; i < size; i++) {
			int nx = water.front().x;
			int ny = water.front().y;
			water.pop();
			for (int k = 0; k < 4; k++) {
				int tx = dx[k] + nx;
				int ty = dy[k] + ny;
				if(safe(tx,ty)&&mat[tx][ty]=='.'){
					mat[tx][ty] = '*';
					water.push({ tx,ty,0 });
				}
			}
		}
		size = me.size();
		for (int i = 0; i < size; i++) {
			int nx = me.front().x;
			int ny = me.front().y;
			int ncnt = me.front().cnt;
			me.pop();
			for (int k = 0; k < 4; k++) {
				int tx = dx[k] + nx;
				int ty = dy[k] + ny;
				if (safe(tx,ty)&&mat[tx][ty] == 'D') {
					printf("%d\n", ncnt+1);
					return 0;
				}
				if (safe(tx, ty) && mat[tx][ty] == '.') {
					mat[tx][ty] = 'S';
					me.push({ tx,ty,ncnt + 1 });
				}
			}
		}
	}
	printf("KAKTUS\n");
	return 0;
}