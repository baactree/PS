#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>


using namespace std;
stack<pair<int,int> > st;
int main(){
	int in,N;
	long long ans = 0;
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++){
		scanf("%d", &in);
		pair<int, int> p = make_pair(in, 1);
		while (!st.empty() && st.top().first <= in){
			ans+=st.top().second;
			if (st.top().first == in)
				p.second += st.top().second;
			st.pop();
		}
		if (!st.empty())
			ans++;
		st.push(p);
	}
	printf("%lld\n", ans);
	return 0;
}