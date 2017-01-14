#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <deque>
#include <stack>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
typedef unsigned long long LLU;

int N,M;
int Q[100];
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		queue<pair<int,int> >q;
		cin >> N >> M;
		int in;
		for (int i = 0; i < N; i++) {
			scanf("%d", &in);
			q.push(make_pair(i,in));
			Q[i] = in;
		}
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
				if (Q[i] < Q[j])
					Q[i] ^= Q[j] ^= Q[i] ^= Q[j];
		int idx = 0;
		int cnt = 0;
		while (true) {
			cnt++;
			int x = q.front().first;
			int y = q.front().second;
			while (y != Q[idx]) {
				q.pop();
				q.push(make_pair(x, y));
				x = q.front().first;
				y = q.front().second;
			}
			q.pop();
			idx++;
			if (x == M)
				break;
		}
		printf("%d\n", cnt);
	}
	return 0;
}