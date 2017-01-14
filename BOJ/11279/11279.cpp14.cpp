#include "bits/stdc++.h"
using namespace std;
template<typename T>
class p_queue {
public:
	T node;
	T *arr;
	int size = 0;
	p_queue(int size) {
		arr = new T[size];
	}
	void swap(T &a, T &b) {
		T temp;
		temp = a;
		a = b;
		b = temp;
	}
	T top() {
		if(size)
			return arr[1];
		return 0;
	}
	void push(T data) {
		int temp = ++size;
		arr[temp] = data;
		while (temp != 1) {
			if (arr[temp / 2] < arr[temp]) {
				swap(arr[temp / 2], arr[temp]);
				temp >>= 1;
				continue;
			}
			break;
		}
	}
	void pop() {
		if (size) {
			int temp = 1;
			swap(arr[temp], arr[size--]);
			while (temp <= size) {
				if (temp * 2 + 1 <= size){
					if (arr[temp] < arr[temp*2]&&arr[temp*2] >= arr[temp*2+1]) {
						swap(arr[temp], arr[temp*2]);
						temp *= 2;
						continue;
					}
					if (arr[temp] < arr[temp*2+1]&&arr[temp*2] <= arr[temp*2+1]) {
						swap(arr[temp], arr[temp*2+1]);
						temp = temp * 2 + 1;
						continue;
					}
				}
				if (temp * 2 <= size) {
					if (arr[temp] < arr[temp * 2]) {
						swap(arr[temp], arr[temp * 2]);
						temp <<= 1;
						continue;
					}
				}
				break;
			}
		}
	}
};
int main() {
	int N;
	int in;
	int now;
	scanf("%d", &N);
	p_queue<int> pq(N + 1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &in);
		if (in) {
			pq.push(in);
		}
		else {
			now = pq.top();
			pq.pop();
			printf("%d\n", now);
		}
	}
	return 0;
}