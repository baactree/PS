#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;
int main() {
	int A[50];
	int B[50];
	A[0] = 1;
	B[0] = 0;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		A[i] = B[i - 1];
		B[i] = A[i - 1] + B[i - 1];
	}
	printf("%d %d\n", A[N], B[N]);
	return 0;
}