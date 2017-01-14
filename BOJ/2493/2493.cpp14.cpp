#include "bits/stdc++.h"
using namespace std;
int N;
stack<pair<int,int> > st;
int ans[500001]; 
int main() {
	scanf("%d", &N);
	int in;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &in);
		while (!st.empty() && st.top().first <= in) 
			st.pop();
		if (st.empty()) {
			ans[i] = 0;
			st.push({ in,i });
		}
		else {
			ans[i] = st.top().second;
			st.push({ in,i });
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}