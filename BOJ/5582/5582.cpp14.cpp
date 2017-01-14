#include "bits/stdc++.h"
using namespace std;
class Suffix_Array {
public:
	struct Comparator {
		const vector<int>& group;
		int t;
		Comparator(const vector<int>& group, int t) :group(group), t(t) {}
		const bool operator () (int a, int b) {
			if (group[a] != group[b])
				return group[a] < group[b];
			return group[a + t] < group[b + t];
		}
	};
	vector<int> get_suffix_array(const string& s) {
		int n = s.length();
		int t = 1;
		vector<int> group(n + 1);
		for (int i = 0; i < n; i++)
			group[i] = s[i];
		group[n] = -1;
		vector<int> perm(n);
		for (int i = 0; i < n; i++)
			perm[i] = i;
		while (true) {
			Comparator cmp(group, t);
			sort(perm.begin(), perm.end(), cmp);
			t <<= 1;
			if (t >= n)
				break;
			vector<int> newGroup(n + 1);
			newGroup[n] = -1;
			newGroup[perm[0]] = 0;
			for (int i = 1; i < n; i++) {
				if (cmp(perm[i - 1], perm[i]))
					newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
				else
					newGroup[perm[i]] = newGroup[perm[i - 1]];
			}
			group = newGroup;
		}
		return perm;
	}
};
class Lcp_Array {
public:
	vector<int> get_lcp_array(const string& s, const vector<int>& sa) {
		int n = s.size(), k = 0;
		vector<int> lcp(n, 0);
		vector<int> rank(n, 0);
		for (int i = 0; i < n; i++)
			rank[sa[i]] = i;
		for (int i = 0; i < n; i++, k ? k-- : 0) {
			if (rank[i] == n - 1) {
				k = 0;
				continue;
			}
			int j = sa[rank[i] + 1];
			while (i + k < n&&j + k < n&&s[i + k] == s[j + k])
				k++;
			lcp[rank[i]] = k;
		}
		return lcp;
	}
};
int main() {
	string a, b;
	cin >> a >> b;
	string str = a +"0"+ b;
	Suffix_Array suffix_array;
	vector<int> sa = suffix_array.get_suffix_array(str);
	Lcp_Array lcp_array;
	vector<int> lcp = lcp_array.get_lcp_array(str, sa);
	int n = a.length();
	int ans = 0;
	int idx;
	for (int i = 0; i < (int)lcp.size()-1; i++) {
		if (sa[i] < n&&sa[i+1]>n) {
			if (ans < lcp[i]) {
				ans = lcp[i];
				idx = sa[i];
			}
		}
		if (sa[i] > n&&sa[i + 1] < n) {
			if (ans < lcp[i]) {
				ans = lcp[i];
				idx = sa[i];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}