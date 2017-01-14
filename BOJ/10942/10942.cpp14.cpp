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
using namespace std;
int N;
int pal[2001];
int M;
bool possi[2001][2001];
void search(int pivot) {
	int left = pivot;
	int right = pivot;
	int k = 0;
	while (left - k > 0 && right + k <= N) {
		if (pal[left - k] == pal[right + k])
			possi[left - k][right + k] = true;
		else
			break;
		k++;
	}
}
void _search(int pivot) {
	int left = pivot;
	int right = pivot + 1;
	int k = 0;
	while (left - k > 0 && right + k <= N) {
		if (pal[left - k] == pal[right + k])
			possi[left - k][right + k] = true;
		else
			break;
		k++;
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <=N; i++) {
		scanf("%d", &pal[i]);
	}
	cin >> M;
	for (int i = 1; i <= N; i++)
		search(i);
	for (int i = 1; i < N; i++)
		_search(i);
	int s, e;
	while (M--) {
		scanf("%d%d", &s, &e);
		if (possi[s][e])
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}