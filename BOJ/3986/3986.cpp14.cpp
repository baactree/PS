#include "bits/stdc++.h"
using namespace std;
string str;
int main() {
	int Case;
	cin >> Case;
	int cnt = 0;
	while (Case--) {
		cin >> str;
		int len = str.length();
		stack<char> st;
		for (int i = 0; i < len; i++) {
			if (st.empty()) {
				st.push(str[i]);
				continue;
			}
			if (st.top() == str[i])
				st.pop();
			else
				st.push(str[i]);
		}
		if (st.empty())
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}