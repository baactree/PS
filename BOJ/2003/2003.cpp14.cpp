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
typedef unsigned int UI;
UI N,M;
UI arr[10000];
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%u", &arr[i]);
	int head, tail;
	head = 0;
	tail = 0;
	UI sum, ans;
	sum = ans = 0;
	while (tail < N) {

		sum += arr[tail];
		if (sum > M) {
			if (head < tail) {
				sum -= arr[head];
				sum -= arr[tail];
				head++;
			}
			else {
				sum -= arr[head];
				head++;
				tail++;
			}
		}
		else if (sum == M) {
			ans++;
			tail++;
		}
		else {
			tail++;
		}
	}
	printf("%u\n", ans);
	return 0;
}




