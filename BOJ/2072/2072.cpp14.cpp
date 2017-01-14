#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <deque>
#include <stack>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
typedef unsigned long long LLU;


int Map[20][20];
int N;
int win;
bool line_search(int x, int y, int mode, int type);
void search(int x, int y, int mode, int i) {
	bool ret = false;
	for (int type = 0; type < 4; type++) {
		if (ret || line_search(x, y, mode, type)) 
			ret = true;
	}
	if (ret)
		win = min(win,i);
}
//type 0 가로
//type 1 좌하 우상
//type 2 세로
//type 3 좌상 우하
bool line_search(int x, int y, int mode, int type) {
	int k, sum;
	switch (type) {
	case 0:
		sum = 1;
		k = 1;
		while (y + k < 20 && Map[x][y + k] == mode) {
			sum++;
			k++;
		}
		k = 1;
		while (y - k > 0 && Map[x][y - k] == mode) {
			sum++;
			k++;
		}
		if (sum == 5)
			return true;
		return false;
	case 1:
		sum = 1;
		k = 1;
		while (x-k>0&&y + k < 20 && Map[x-k][y + k] == mode) {
			sum++;
			k++;
		}
		k = 1;
		while (x+k<20&&y - k > 0 && Map[x+k][y - k] == mode) {
			sum++;
			k++;
		}
		if (sum == 5)
			return true;
		return false;
	case 2:
		sum = 1;
		k = 1;
		while (x - k>0&& Map[x - k][y] == mode) {
			sum++;
			k++;
		}
		k = 1;
		while (x + k<20&& Map[x + k][y ] == mode) {
			sum++;
			k++;
		}
		if (sum == 5)
			return true;
		return false;
	case 3:
		sum = 1;
		k = 1;
		while (x - k>0 && y - k >0 && Map[x - k][y - k] == mode) {
			sum++;
			k++;
		}
		k = 1;
		while (x + k<20 && y + k < 20 && Map[x + k][y + k] == mode) {
			sum++;
			k++;
		}
		if (sum == 5)
			return true;
		return false;
	}
}
int main() {
	int x, y;
	//흑 = 2 백 = 1
	int mode;
	//흑 = 2 백 = 1
	win = 987654321;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		mode = (i % 2) + 1;
		scanf("%d%d", &x, &y);
		Map[x][y] = mode;
		search(x, y, mode, i);
	}
	if (win == 987654321)
		printf("-1\n");
	else
		printf("%d\n", win);
	return 0;
}