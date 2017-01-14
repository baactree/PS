#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	int ans = 0;
	int a;
	char calc;
	scanf("%d\n%c", &a, &calc);
	ans = a;
	int b;
	char d;
	while (true) {
		switch (calc) {
		case '+':
			scanf("%d\n%c", &b, &d);
			ans += b;
			break;
		case '-':
			scanf("%d\n%c", &b, &d);
			ans -= b;
			break;
		case '/':
			scanf("%d\n%c", &b, &d);
			ans /= b;
			break;
		case '*':
			scanf("%d\n%c", &b, &d);
			ans *= b;
			break;
		case '=':
			printf("%d\n", ans);
			return 0;
			break;
		}
		calc = d;
	}

	return 0;
}