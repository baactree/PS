// =====================================================================================
// 
//       Filename:  Stackig_Plates.cpp
//        Created:  2017년 04월 12일 23시 02분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
int N;
int cache[2501][51];
int b[51];
vector<pair<int, int> > dish;
int solve(int idx,int front) {
	if (idx == dish.size())
		return 0;
	int &ret = cache[idx][front];
	if (ret != -1)
		return ret;
	ret = INF;
	int now = dish[idx].first;
	int st, fi;
	st = fi = idx;
	while (fi + 1 < dish.size() && dish[fi].first == dish[fi + 1].first)
		fi++;
	int cnt = 0;
	bool flag = false;
	int fidx;
	for (int i = st; i <= fi; i++) {
		if (b[dish[i].second] != now)
			cnt++;
		if (dish[i].second == front) {
			fidx = i;
			flag = true;
		}
	}
	if (flag) {
		//front에서 이어서 만드는 방법이 존재함
		for (int i = st; i <= fi; i++) {
			if (st!=fi&&i == fidx)
				continue;
			ret = min(ret, solve(fi + 1, dish[i].second) + fi - st + cnt - 1);
		}
	}
	for (int i = st; i <= fi; i++) 
		ret = min(ret, solve(fi + 1, dish[i].second) + fi - st + 1 + cnt);
	return ret;
}
int main() {
	int TestCase;
	scanf("%d", &TestCase);
	for (int tc=1;tc<=TestCase;tc++) {
		memset(b, -1, sizeof(b));
		dish.clear();
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int h;
			scanf("%d", &h);
			while (h--) {
				int r;
				scanf("%d", &r);
				dish.push_back({ r,i });
				b[i] = max(b[i], r);
			}
		}
		sort(dish.begin(), dish.end());
		dish.erase(unique(dish.begin(), dish.end()), dish.end());
		memset(cache, -1, sizeof(cache));
		printf("#testcase%d\n%d\n", tc,solve(0,50)-1);
	}
	return 0;
}
