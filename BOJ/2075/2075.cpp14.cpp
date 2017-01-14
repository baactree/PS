#include "bits/stdc++.h"
using namespace std;
char buf[1 << 17];
int idx, nidx, N;
static inline char read() {
	if (idx == nidx) {
		nidx = fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
static inline int readInt() {
	int sum = 0;
	bool flag = false;
	char now = read();
	while (now == ' ' || now == '\n')
		now = read();
	if (now == '-') {
		flag = true;
		now = read();
	}
	while (now != ' '&&now != '\n') {
		sum *= 10;
		sum += now - '0';
		now = read();
	}
	return flag ? -sum : sum;
}
priority_queue<int> pq;
int main() {
	N = readInt();
	int temp;
	for (int i = 0; i < N; i++) {
		temp = readInt();
		pq.push(-temp);
	}
	for (int i = N; i < N*N; i++) {
		temp = readInt();
		if (-pq.top() >= temp)
			continue;
		else {
			pq.pop();
			pq.push(-temp);
		}
	}
	printf("%d\n", -pq.top());
	return 0;
}