#include "bits/stdc++.h"
using namespace std;
struct event {
	bool start;
	int left, right, radius;
	event(bool start, int left, int right, int radius) :
		start(start), left(left), right(right), radius(radius) {}
	inline int cmp() const {
		return start ? left : right;
	}
	bool operator < (const event &rhs) const {
		if (cmp() != rhs.cmp())
			return cmp() < rhs.cmp();
		if (start != rhs.start)
			return start < rhs.start;
		return radius > rhs.radius;
	}
};

int N;
vector<event> events;
stack<int> st;
int main() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		events.push_back(event(true, a - b, a + b, b));
		events.push_back(event(false, a - b, a + b, b));
	}
	sort(events.begin(), events.end());
	int ans = 1;
	for (int i = 0; i < events.size(); i++) {
		if (!st.empty()) {
			if (st.top() == 0 || st.top() == 1)
				st.top() = (events[i].cmp() == events[i - 1].cmp()) ? 1 : 2;
		}
		if (events[i].start)
			st.push(0);
		else {
			if (st.top() == 1)
				ans += 2;
			else
				ans++;
			st.pop();
		}
	}
	printf("%d\n", ans);
	return 0;
}