#include "bits/stdc++.h"
using namespace std;
#define SIZE 100000
#define INF 0x3fffffff;
int arr[SIZE];
int RMQ[SIZE * 4];
int N, M;
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
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	init(0, N - 1, 1);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", query(a-1, b-1, 1, 0, N - 1));
	}
	return 0;
}