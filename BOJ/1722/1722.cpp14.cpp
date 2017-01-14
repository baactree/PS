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
typedef long long int ll;
ll fact[21];
bool use[21];
int main()
{
	fact[0] = 1;
	int arr[20];
	for (int i = 1; i < 21; i++)
		fact[i] = fact[i - 1] * i;
	int N,mode;
	cin >> N>>mode;
	if (mode == 1) {
		ll K;
		cin >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				if (use[j])
					continue;
				if (fact[N - i - 1] < K)
					K -= fact[N - i - 1];
				else {
					arr[i] = j;
					use[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < N; i++) 
			printf("%d ", arr[i]);
		printf("\n");
	}
	else {
		for (int i = 0; i < N;i++)
			scanf("%d", &arr[i]);
		ll ans = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < arr[i]; j++)
				if (!use[j])
					ans += fact[N - i - 1];
			use[arr[i]] = true;
		}
		printf("%lld\n", ans);
	}
	return 0;
}