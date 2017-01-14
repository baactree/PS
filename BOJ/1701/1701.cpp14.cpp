#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;
string str;
int len;
int SuffixArr[5000];
struct Suffix {
	const string& s;
	Suffix(const string& s):s(s) {}
	bool operator () (int i, int j) {
		return strcmp(s.c_str() + i, s.c_str() + j) < 0;
	}
};
void getSuffix() {
	sort(SuffixArr, SuffixArr + len, Suffix(str));
}
int compare(int i, int j) {
	int k = 0;
	while (i < len&&j < len&&str[i] == str[j]) {
		i++;
		j++;
		k++;
	}
	return k;
}

int main() {
	cin >> str;
	len = str.length();
	for (int i = 0; i < len; i++)
		SuffixArr[i] = i;
	getSuffix();

	int ans = -1;
	int length;
	for (int i = 0; i < len; i++) {
		if (i > 0) {
			length = compare(SuffixArr[i - 1], SuffixArr[i]);
			ans = max(ans, length);
		}
	}
	printf("%d\n", ans);
	return 0;
}