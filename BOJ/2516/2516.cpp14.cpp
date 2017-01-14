#include "bits/stdc++.h"
using namespace std;
int N;
int arr[100001][4];
bool loca[1000001];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i][0]);
		for (int j = 0; j < arr[i][0]; j++)
			scanf("%d", &arr[i][j + 1]);
	}
	bool updated = true;
	while (updated) {
		updated = false;
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 1; j <= arr[i][0]; j++)
				if (loca[i+1] == loca[arr[i][j]])
					cnt++;
			if (cnt > 1) {
				updated = true;
				if (loca[i+1])
					loca[i+1] = false;
				else
					loca[i+1] = true;
			}
		}
	}
	int cnt, cnt2;
	cnt = cnt2 = 0;
	for (int i = 1; i <= N; i++)
		if (loca[i])
			cnt++;
		else
			cnt2++;
	if (cnt == 0) {
		loca[1] = true;
		cnt++;
		cnt2--;
	}
	else if (cnt == N) {
		loca[1] = false;
		cnt--;
		cnt2++;
	}
	printf("%d", cnt);
	for (int i = 1; i <= N; i++)
		if (loca[i])
			printf(" %d", i);
	printf("\n");
	printf("%d", cnt2);
	for (int i = 1; i <= N; i++)
		if (!loca[i])
			printf(" %d", i);
	printf("\n");
	return 0;
}