#include "bits/stdc++.h"	
using namespace std;
int N;
stack <int> st;
int hi[100001];
int main() {
	scanf("%d", &N);
	int in;
	for (int i = 0; i < N; i++)
		scanf("%d", &hi[i]);
	int ans = 0;
	for (int i = 0; i <= N; i++) {
		while (!st.empty() && hi[st.top()] >= hi[i]) {
			int j = st.top();
			st.pop();
			int width;
			if (st.empty())
				width = i;
			else
				width = (i - st.top() - 1);
			ans = max(ans, hi[j] * width);
		}
		st.push(i);
	}
	printf("%d\n", ans);
	return 0;
}