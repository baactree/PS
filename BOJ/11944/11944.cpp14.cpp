#include "bits/stdc++.h"
using namespace std;
int N, M;
string str;
int main() {
	cin >> str >> M;
	int cnt = 0;
	int len = str.length();
	int temp = stoi(str);
	while (temp--) {
		for (int i = 0; i < len; i++) {
			printf("%c", str[i]);
			cnt++;
			if (cnt == M)
				return 0;
		}
	}
	return 0;
}