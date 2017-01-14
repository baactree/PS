#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;
string num;
int main() {
	int Case;
	int n;
	int reverse;
	int sum;
	int len;
	cin >> Case;
	while (Case--) {
		scanf("%d",&n);
		int temp = n;
		reverse = 0;
		while (temp != 0) {
			reverse *= 10;
			reverse += temp % 10;
			temp /= 10;
		}
		sum = reverse + n;
		len = 0;
		temp = sum;
		while(temp != 0) {
			len++;
			temp /= 10;
		}
		temp = sum;
		reverse = 0;
		while (temp != 0) {
			reverse *= 10;
			reverse += temp % 10;
			temp /= 10;
		}
		while (sum!=0) {
			if (sum % 10 != reverse % 10)
				break;
			sum /= 10;
			reverse /= 10;
		}
		if (sum != 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}