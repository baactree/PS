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

using namespace std;

#define None -987654321
int N;
int store[10000];
bool cache[10000];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &store[i]);
	}
	//소팅
	sort(store, store + N);
	//0과 1의 인덱스를 구함
	int idx_0 = None;
	int idx_1 = None;
	for (int i = 0; i < N; i++) {
		if (store[i] == 1)
			idx_1 = i;
		if (store[i] == 0)
			idx_0 = i;
	}

	//answer구함
	int idx = 0;
	int sum = 0;
	//음수합 구하는 반복문
	while (store[idx + 1] < 0){
		sum += store[idx] * store[idx + 1];
		cache[idx] = true;
		cache[idx + 1] = true;
		idx += 2;
	}

	idx = N - 1;
	//양수합을 구하는 반복문
	while (store[idx - 1] > 1) {
		sum += store[idx] * store[idx - 1];
		cache[idx] = true;
		cache[idx - 1] = true;
		idx -= 2;
	}

	//1이 있다면 그냥 더함
	if (idx_1 != None) {
		sum++;
		cache[idx_1] = true;
	}

	for (int i = 0; i < N; i++) {
		if (!cache[i]) {
			if (store[i] < 0) {
				//음수가 남아있고 0이 없다면 그냥 더함
				if (idx_0 == None) {
					sum += store[i];
					cache[i] = true;
				}
			}
			else {
				sum += store[i];
				cache[i] = true;
			}
			
		}
	}


	printf("%d\n", sum);
	return 0;
}
