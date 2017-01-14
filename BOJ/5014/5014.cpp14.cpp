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
int f, s, g, u, d;
bool cache[1000001];
queue<int> q;
int search(){
	q.push(s);
	int ret=0;
	while (!q.empty()){
		int size = q.size();
		for (int i = 0; i < size; i++){
			int now = q.front();
			q.pop();
			if (now == g)
				return ret;
			if (now + u <= f&&!cache[now+u]){
				cache[now + u] = true;
				q.push(now + u);
			}
			if (now - d > 0&&!cache[now - d]){
				cache[now - d ] = true;
				q.push(now - d);
			}
		}
		ret++;
	}
	return -1;
}
int main(){
	cin >> f >> s >> g >> u >> d;
	int ans = search();
	if (ans == -1)
		printf("use the stairs\n");
	else
		printf("%d\n", ans);
	return 0; 
}