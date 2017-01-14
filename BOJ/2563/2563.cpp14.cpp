#include "bits/stdc++.h"
using namespace std;
int N;
bool Map[101][101];
void search(int a, int b) {
	for (int i = a; i < a + 10; i++)
		for (int j = b; j < b + 10; j++)
			Map[i][j] = true;
}
int main() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		search(a, b);
	}
	int ans = 0;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (Map[i][j])
				ans++;
	printf("%d\n", ans);
	return 0;
}