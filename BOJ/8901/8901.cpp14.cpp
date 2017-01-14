#include "bits/stdc++.h"
using namespace std;
int main(){
	int Case;
	cin >> Case;
	while (Case--) {
		int A, B, C;
		int AB, BC, CA;
		int ans = 0;
		scanf("%d%d%d%d%d%d", &A, &B, &C, &AB, &BC, &CA);
		for (int ab = 0; ab <= min(A, B); ab++) {
			for (int bc = 0; bc <= min(C, B-ab); bc++) {
				int temp = ab*AB;
				temp += bc*BC;
				temp += min(A - ab, C-bc)*CA;
				ans = max(ans, temp);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}