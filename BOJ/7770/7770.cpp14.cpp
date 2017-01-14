#include "bits/stdc++.h"
using namespace std;
/*
1 1
2 1 + 1 +(2-1)*4 = 6
3  6 + ( 6 - 1 )  + (3-1)*4 = 20
*/
int arr[1000000];
int main() {
	int N;
	cin >> N;
	arr[1] = 1;
	int ans = 1;
	for (int i = 2;; i++) {
		arr[i] = arr[i - 1] * 2 - arr[i - 2] + (i - 1) * 4;
		if (arr[i] > N)
			break;
		ans = i;
	}
	printf("%d\n", ans);
	return 0;
}