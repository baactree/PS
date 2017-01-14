#include "bits/stdc++.h"
using namespace std;
int N;
int Map[64][64];
bool chk(int x, int y, int k) {
	int now = Map[x][y];
	for (int i = x; i < x + k; i++)
		for (int j = y; j < y + k; j++)
			if (now != Map[i][j])
				return false;
	return true;
}
string search(int x, int y,int k) {
	if (chk(x, y, k)) 
		return string(1,Map[x][y] + '0');
	string ret = "(";
	k /= 2;
	ret += search(x, y, k);
	ret += search(x, y + k, k);
	ret += search(x + k, y, k);
	ret += search(x + k, y + k, k);
	ret += ")";
	return ret;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &Map[i][j]);
	cout << search(0, 0, N) << endl;
	return 0;
}