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

void _swap(int a, int b, int *A)
{
	A[a] ^= A[b] ^= A[a] ^= A[b];
}
void _sort(int left, int right, int *A)
{
	int mid = (left + right) / 2;
	int le = left;
	int ri = right;
	int pivot = left;
	left++;
	while (right > left)
	{
		while (A[right] >= A[pivot] && right > left)
			right--;
		while (A[left] <= A[pivot] && right > left)
			left++;
		if (right > left&&A[right]!=A[left])
			_swap(left, right, A);
	}

	if (A[left] < A[pivot])
	{
		_swap(left, pivot, A);
		pivot = left;
	}
	if (le < pivot - 1)
		_sort(le, pivot - 1, A);
	if (pivot + 1 < ri)
		_sort(pivot + 1, ri, A);
}

int main()
{
	int arr[1002];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr,arr+n);
	int sum = 0;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		result += sum;
	}
	cout << result << endl;
	return 0;
}