#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;
int N, D;
double v, f, c;
int main(){
	int Case;
	cin >> Case;
	while (Case--) {
		scanf("%d%d", &N, &D);
		int ans = 0;
		for (int i = 0; i < N; i++) {
			scanf("%lf%lf%lf", &v, &f, &c);
			if (v / c*f + 0.000000001 >= D)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}