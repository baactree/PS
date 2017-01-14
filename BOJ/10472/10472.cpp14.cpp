#include "bits/stdc++.h"
using namespace std;
char Map[3][4];
int table[5][5];
int search(int x, int y) {
	if (x == 4) {
		bool flag = false;
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				if (table[i][j] == 1)
					flag = true;
		if (flag)
			return 987654321;
		else
			return 0;
	}
	if (y == 4)
		return search(x + 1, 1);
	
	int ret;
	ret = search(x, y + 1);

	int temp[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			temp[i][j] = table[i][j];

	table[x][y] *= -1;
	table[x - 1][y] *= -1;
	table[x + 1][y] *= -1;
	table[x][y - 1] *= -1;
	table[x][y + 1] *= -1;
	ret = min(ret, search(x, y + 1) + 1);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			table[i][j] = temp[i][j];
	return ret;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(table, -1, sizeof(table));
		for (int i = 0; i < 3; i++)
			scanf("%s", &Map[i]);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (Map[i][j] == '*')
					table[i + 1][j + 1] = 1;
		printf("%d\n", search(1, 1));
	}
	return 0;
}