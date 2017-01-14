#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int N;
bool Map[11][11];
int trip[11][11];
bool even;
int Max = 0;
void search(int v,int cnt) {
	if (v >= N*N) {
		Max = max(Max, cnt);
		return ;
	}
	if ((N*N - v)/2+1 + cnt <= Max)
		return;
	int x = v / N;
	int y = v%N;
	if (Map[x][y] == 0 || trip[x][y] != 0) {
		if (even) {
			if (y + 2 == N)
				search(v + 3,cnt);
			else if (y + 1 == N)
				search(v + 1,cnt);
			else
				search(v + 2,cnt);
		}
		else
			search(v + 2,cnt);
		return;
	}

	int k = 1;
	while (x + k < N&&y + k < N) {
		trip[x + k][y + k]++;
		k++;
	}
	k = 1;
	while (x + k < N&&y - k >=0) {
		trip[x + k][y - k]++;
		k++;
	}
	trip[x][y]++;

	if (even) {
		if (y + 2 == N)
			search(v + 3,cnt+1);
		else if (y + 1 == N)
			search(v + 1,cnt+1);
		else
			search(v + 2,cnt+1);
	}
	else
		search(v + 2,cnt+1);

	k = 1;
	while (x + k < N&&y + k < N) {
		trip[x + k][y + k]--;
		k++;
	}
	k = 1;
	while (x + k < N&&y - k >=0) {
		trip[x + k][y - k]--;
		k++;
	}
	trip[x][y]--;



	if (even) {
		if (y + 2 == N)
			search(v + 3, cnt);
		else if (y + 1 == N)
			search(v + 1, cnt);
		else
			search(v + 2, cnt);
	}
	else
		search(v + 2, cnt);





}
int main() {
	scanf("%d", &N);
	if (N % 2 == 0)
		even = true;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &Map[i][j]);

	int ans = 0;
	search(0,0);
	ans = Max;
	Max = 0;
	search(1,0);
	ans += Max;
	printf("%d\n", ans);

	return 0;
}