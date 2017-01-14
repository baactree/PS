/*

VCPP, GPP에서 사용

*/
#include <stdio.h>
#include <iostream>
using namespace std;

extern inline void _swap(int a, int b, int *A)
{
	A[a] ^= A[b] ^= A[a] ^= A[b];
}
void _sort(int left, int right, int *A)
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
		while (A[right] >= A[pivot] && right > left)
			right--;
		while (A[left] <= A[pivot] && right > left)
			left++;
		if (right > left)
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

int item[1000];
int N;
int main()
{

		
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &item[i]);
		
		_sort(0, N - 1, item);

		int sum = 0;
		if (item[0] == 1)
		{
			sum = 1;
			for (int i = 1; i < N; i++)
			{
				if (item[i]>sum+1)
					break;
				sum += item[i];
			}
		}

		

		printf("%d\n",sum+1);


		/*

		알고리즘이 들어가는 부분

		*/


	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}