#include <iostream>
#include <stdio.h>

using namespace std;
typedef unsigned long long ULL;
ULL A, B, C;
ULL search(ULL A, ULL B) {
	if (B == 0)
		return 1;
	if (B == 1)
		return A%C;
	if (B == 2)
		return (A%C*A%C)%C;
	ULL temp = search(A, B / 3);
	int t = B % 3;
	if (t == 0)
		return ((((temp%C)*temp%C) % C)*temp%C) % C;
	if (t == 1)
		return ((((((temp%C)*temp%C) % C)*temp%C) % C)*A%C) % C;
	if (t == 2)
		return ((((((((temp%C)*temp%C) % C)*temp%C) % C)*A%C) % C)*A%C) % C;
}
int main() {
	cin >> A >> B >> C;
	printf("%llu\n", search(A, B));
	return 0;
}