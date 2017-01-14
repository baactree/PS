#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>
#include <queue>
using namespace std;
stack<int>line[7];
int N, P;
int main(void) {
	cin >> N >> P;
	int a, b;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		if (line[a].empty()) {
			line[a].push(b);
			ans++;
		}
		else {
			if (line[a].top() < b) {
				line[a].push(b);
				ans++;
			}
			else if (line[a].top() > b) {
				while (!line[a].empty()&&line[a].top() > b) {
					line[a].pop();
					ans++;
				}
				if (line[a].empty()||line[a].top() < b) {
					line[a].push(b);
					ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
	return  0;
}