#include "bits/stdc++.h"
using namespace std;
int main() {
	int n;
	string str;
	cin >> n >> str;
	vector<int> pi(n);
	int begin = 1, matched = 0;
	while (begin + matched < n) {
		if (str[begin + matched] == str[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin = begin + matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	cout << n - pi[n - 1] << endl;
	return 0;
}