#include "bits/stdc++.h"
using namespace std;
int mod[42];
int arr[10];
int main() {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
		mod[arr[i] % 42]++;
	}
	int cnt = 0;
	for (int i = 0; i < 42; i++)
		if (mod[i])
			cnt++;
	printf("%d\n", cnt);
	return 0;
}