#include "bits/stdc++.h"
using namespace std;
int _time[3];
bool picked[3];
int pick[3];
int search(int n) {
	if (n == 3) {
		if (pick[0] >= 1 && pick[0] <= 12)
			if (pick[1] >= 0 && pick[1] <= 59)
				if (pick[2] >= 0 && pick[2] <= 59)
					return 1;
		return 0;
	}
	int ret = 0;
	for (int i = 0; i < 3;i++)
		if (!picked[i]) {
			picked[i] = true;
			pick[n] = _time[i];
			ret += search(n + 1);
			picked[i] = false;
		}
	return ret;
}
int main() {
	scanf("%2d:%2d:%2d", &_time[0], &_time[1], &_time[2]);
	printf("%d\n", search(0));
	return 0;
}