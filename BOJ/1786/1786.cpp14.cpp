#include "bits/stdc++.h"
using namespace std;
string T, P;
vector<int> ans;
int pi[1000001];
int len_p;
int len_t;
void make_pi() {
	int i = 0, j = -1;
	pi[0] = -1;
	while (i < len_p) {
		if (j == -1 || P[i] == P[j]) {
			i++; j++;
			pi[i] = j;
		}
		else
			j = pi[j];
	}
}
int main() {
	getline(cin, T);
	getline(cin, P);
	len_t = T.length();
	len_p = P.length();
	int i, j;
	i = j = 0;
	make_pi();
	while (i < len_t) {
		if (j == -1 || T[i] == P[j]) {
			i++; j++;
		}
		else
			j = pi[j];
		if (j == len_p) {
			ans.push_back(i-len_p);
			j = pi[j];
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i] + 1);
	return 0;
}