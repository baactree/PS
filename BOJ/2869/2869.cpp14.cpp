#include "bits/stdc++.h"
using namespace std;
int A, B, V;
int main() {
	scanf("%d%d%d", &A, &B, &V);
	V -= A;
	if (V <= 0)
		printf("1\n");
	else {
		printf("%d\n", (V + A - B - 1) / (A - B) + 1);
	}
	return 0;
}