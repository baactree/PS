
#pragma optimize("-O2")
#include <iostream>
#include <stdio.h>
using namespace std;

int input[100000];



//소팅에 함정이 있었음
//퀵소트라도 중앙갑 정렬안하고 left값 정렬하면
//N^2로 계산되는듯

extern inline void __attribute__((optimize("-O2")))_swap(int a, int b, int *A)
{
	A[a] ^= A[b] ^= A[a] ^= A[b];
}
void __attribute__((optimize("-O2")))_sort(int left, int right, int *A)
{
	int mid = (left + right) / 2;
	int le = left;
	int ri = right;
	int pivot = left;
	if (pivot != mid)
	{
		_swap(mid, pivot, A);
	}
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
//+1 하면 data보다 같거나 작은 것들의 갯수 O(logn)에 구함 즉 인덱스
int __attribute__((optimize("-O2")))search(int left, int right, int data, int *A)
{
	if (data < A[left])
		return left - 1;
	if (left == right)
		return left;
	int mid = (left + right) / 2;
	if (A[mid] == data)
		return mid;
	if (A[mid] < data&&mid + 1 <= right)
		return search(mid + 1, right, data, A);
	if (data < A[mid] && mid - 1 >= left)
		return search(left, mid - 1, data, A);
}

//O(NlogN)
//스택을 이용하면 O(N)풀이가 있을거 같은데 몰겟음
int __attribute__((optimize("-O2")))main()
{
	
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &input[i]);
		_sort(0, N - 1, input);

		int index;
		int Min = 0x7fffffff;
		int m_now, m_index;
		m_index = m_now = 0;
		for (int i = 0; i < N; i++)
		{
			index = search(0, N - 1, (-1)*input[i], input);
			//cout << index << endl;
			int sum_f, sum_b, sum;
			int index_f, index_b;
			index_f = index;
			index_b = index + 1;

			if (index_f == -1)
				index_f = index_b;
			if (index_b == N)
				index_b--;
			if (index_f == i)
			{
				if (index_f != 0)
					index_f--;
				else
					index_f++;
			}
			if (index_b == i)
			{
				if (index_b != N - 1)
					index_b++;
				else
					index_b--;
			}


			sum_f = input[index_f] + input[i];
			sum_f = sum_f < 0 ? (-1)*sum_f : sum_f;

			sum_b = input[index_b] + input[i];
			sum_b = sum_b < 0 ? (-1)*sum_b : sum_b;

			if (sum_f >= sum_b)
			{
				index = index_b;
				sum = sum_b;
			}
			else
			{
				sum = sum_f;
				index = index_f;
			}




			if (Min > sum)
			{
				Min = sum;
				m_now = i;
				m_index = index;
			}

		}
		printf("%d %d\n", input[m_now], input[m_index]);


	
	return 0;

}