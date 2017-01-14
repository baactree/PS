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
	int cnt = 1;
	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			break;
		printf("%d. ", cnt);
		cnt++;
		if ((N * 3) & 1) {
			printf("odd ");
			int temp = ((N * 3) + 1) / 2;
			printf("%d\n", temp / 3);
		}
		else {
			printf("even ");
			int temp = N * 3 / 2;
			printf("%d\n", temp / 3);
		}
	}
	return 0;
}