#include <bits/stdc++.h>
using namespace std;
int N,K;
int Map[100001];
bool trip[100001];
int main(){
	cin >> N >> K;
	queue<int> q;
	q.push(N);
	trip[N] = true;
	while (!q.empty()){
		int now = q.front();
		q.pop();
		if (now == K)
			break;
		if (now - 1 >= 0 && !trip[now - 1]){
			trip[now - 1] = true;
			Map[now - 1] = Map[now] + 1;
			q.push(now - 1);
		}
		if (now + 1 <= 100000 && !trip[now + 1]){
			trip[now + 1] = true;
			Map[now + 1] = Map[now] + 1;
			q.push(now + 1);
		}
		if (now * 2 <= 100000 && !trip[now * 2 ]){
			trip[now * 2] = true;
			Map[now * 2] = Map[now] + 1;
			q.push(now * 2);
		}
	}
	printf("%d\n", Map[K]);
	return 0;
}
