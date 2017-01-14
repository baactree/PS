#include "bits/stdc++.h"
using namespace std;
#define SIZE 5000000
#define INF 0x7fffffff;
int arr[SIZE];
int RMQ[SIZE*4];
static char buf[262144];
static int idx, nidx;
int N, M;
static inline int read() {
	if (idx == nidx) {
		nidx = fread(buf, 1, 262144, stdin);
		idx = 0;
	}
	return buf[idx++];
}
static inline int readInt() {
	int sum=0;
	bool flag=true;
	char now;
	now = read();
	if (now == '-') {
		flag = false;
		now = read();
	}
	while (now != ' '&&now != '\n') {
		sum *= 10;
		sum += now - '0';
		now = read();
	}
	if (flag)
		return sum;
	return -sum;
}
int init(int left, int right, int node) {
	if (left == right)
		return RMQ[node] = arr[left];
	int mid = (right + left) / 2;
	int left_min = init(left, mid, node * 2);
	int right_min = init(mid + 1, right, node * 2 + 1);
	return RMQ[node] = min(left_min, right_min);
}
int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (right < nodeLeft || nodeRight < left) return INF;
	if (left <= nodeLeft&&nodeRight <= right)
		return RMQ[node];
	int mid = (nodeLeft + nodeRight) / 2;
	return min(query(left, right, node * 2, nodeLeft, mid),
		query(left, right, node * 2 + 1, mid + 1, nodeRight));
}

int main() {
	scanf("%d%d", &N, &M);
	read();
	for (int i = 0; i < N; i++)
		arr[i] = readInt();
	init(0, N - 1, 1);
	int _min = INF;
	for (int i = 0; i < M; i++) {
		_min = min(_min, arr[i]);
		printf("%d ", _min);
	}
	for (int i = M; i < N; i++) {
		if (_min == arr[i - M]) {
			_min = query(i - M + 1, i, 1, 0, N - 1);
			printf("%d ", _min);
		}
		else {
			_min = min(_min, arr[i]);
			printf("%d ", _min);
		}
	}
	return 0;
}