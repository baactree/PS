#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;
int main() {
	int Case;
	cin >> Case;
	for (int tc = 1; tc <= Case; tc++) {
		printf("String #%d\n", tc);
		string in;
		cin >> in;
		int len = in.length();
		for (int i = 0; i < len; i++) {
			in[i] = ((in[i] - 65 + 1) % 26) + 65;
		}
		cout << in << "\n\n";
	}
	return 0;
}