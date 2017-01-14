#include "bits/stdc++.h"
using namespace std;
int N;
pair<int, int> arr[50];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	for (int i = 0; i < N; i++) {
		int grade = 1;
		pair<int, int> now = arr[i];
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (now.first < arr[j].first&&now.second < arr[j].second)
				grade++;
		}
		printf("%d ", grade);
	}
	return 0;
}