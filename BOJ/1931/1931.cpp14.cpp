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

using namespace std;

int N;
int meeting[100000][2];

extern inline void _swap(int a, int b, int A[][2]);
void _sort(int left, int right, int A[][2]);


int main() {
	cin >> N;
	int b, e;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &meeting[i][0], &meeting[i][1]);
	}
	_sort(0, N - 1, meeting);
	int _front = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int m_b = meeting[i][0];
		int m_e = meeting[i][1];

		if (_front <= m_b) {
			_front = m_e;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}


extern inline void _swap(int a, int b, int A[][2])
{
	int temp[2];
	for (int i = 0; i < 2; i++) {
		temp[i] = A[a][i];
		A[a][i] = A[b][i];
		A[b][i] = temp[i];
	}
}
void _sort(int left, int right, int A[][2])
{
	int mid = (left + right) / 2;
	int le = left;
	int ri = right;
	int pivot = left;
	if (pivot != mid)
		_swap(mid, pivot, A);
	left++;
	while (right > left)
	{
		while (A[right][1] >= A[pivot][1] && right > left)
			right--;
		while (A[left][1] <= A[pivot][1] && right > left)
			left++;
		if (right > left)
			_swap(left, right, A);
	}

	if (A[left][1] < A[pivot][1])
	{
		_swap(left, pivot, A);
		pivot = left;
	}
	if (le < pivot - 1)
		_sort(le, pivot - 1, A);
	if (pivot + 1 < ri)
		_sort(pivot + 1, ri, A);
}
