#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>


using namespace std;

struct ball {
	int size;
	int idx;
	int col;
};
ball arr[200001];
int ans[200001];
int sum;
int N;
bool cmp(const ball &a, const ball &b) {
	return a.size < b.size;
}
bool cmp2(const ball &a, const ball &b) {
	return a.col < b.col;
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &arr[i].col, &arr[i].size);
		arr[i].idx = i;
	}
	arr[0].idx = arr[0].col = arr[0].size = 0;
	sort(arr + 1, arr + 1 + N, cmp);
	for (int i = 1; i <= N; i++) {
		if (arr[i].size == arr[i - 1].size) {
			ans[arr[i].idx] = ans[arr[i - 1].idx];
			sum+=arr[i-1].size;
		}
		else {
			sum+=arr[i - 1].size;
			ans[arr[i].idx] = sum;
		}
	}
	stable_sort(arr + 1, arr + 1 + N, cmp2);
	sum = 0;
	for (int i = 1; i <=N; i++) {
		if (arr[i].col == arr[i - 1].col) {
			if (arr[i].size == arr[i - 1].size) {
				ans[arr[i].idx] = ans[arr[i - 1].idx];
				sum += arr[i - 1].size;
			}
			else {
				sum += arr[i - 1].size;
				ans[arr[i].idx] -= sum;
			}
		}
		else 
			sum = 0;
	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", ans[i]);
}