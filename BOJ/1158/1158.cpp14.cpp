#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int N, M;
queue<int> q;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		q.push(i);
	printf("<");
	while (!q.empty()) {
		int k = 1;
		while (k != M) {
			q.push(q.front());
			q.pop();
			k++;
		}
		printf("%d", q.front());
		q.pop();
		if (!q.empty())
			printf(", ");
	}
	printf(">\n");
	return 0;
}