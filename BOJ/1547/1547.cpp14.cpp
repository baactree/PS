#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

int cup[4];
using namespace std;
int main() {
	cup[1] = 1;
	int N;
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		swap(cup[a], cup[b]);
	}
	for (int i = 1; i <= 3; i++)
		if (cup[i] == 1)
			printf("%d\n", i);
	return 0;
}