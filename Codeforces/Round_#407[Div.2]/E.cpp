// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 04월 07일 22시 25분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
bool trip[3000];
int main() {
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; i++) {
		int in;
		scanf("%d", &in);
		arr.push_back(in - k);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	queue<pair<int,int> > q;
	q.push({ 0,0 });
	int ans = -1;
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (now == 0 && trip[now+1500]) {
			ans = cnt;
			continue;
		}
		for (int i = 0; i < arr.size(); i++) {
			int next = now + arr[i];
			if (next + 1500 >= 0 && next + 1500 < 3000 && !trip[next+1500]) {
				trip[next + 1500] = true;
				q.push({ next,cnt + 1 });
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
