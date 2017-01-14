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
int A[500000];
int B[500000];
int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		B[i] = A[i];
	}
	sort(B, B + N);
	int ans = -1;
	for (int i = 0; i < N; i++) {
		int temp;
		if (A[i] == B[i])
			temp = 0;
		else if (A[i] > B[i])
			temp = 1;
		else {
			int idx = -1;
			int l, r, mid;
			l = 0; r = N - 1;
			while (r >= l) {
				mid = (r + l) / 2;
				if (B[mid] == A[i]) {
					idx = max(idx, mid);
					l = mid + 1;
				}
				else if (B[mid] < A[i]) {
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
			temp = i - idx;
		}

		ans = max(ans, temp);
	}
	printf("%d\n", ans + 1);
	return 0;
}