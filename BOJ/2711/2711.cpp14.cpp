#include "bits/stdc++.h"
using namespace std;
char input[81];
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int idx;
		scanf("%d%s", &idx, input);
		int len = strlen(input);
		for (int i = 0; i < len; i++) {
			if (i == idx - 1)
				continue;
			printf("%c", input[i]);
		}
		printf("\n");
	}
	return 0;
}