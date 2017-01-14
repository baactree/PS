#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int N, M;
char Map[50][51];
int main(void){
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%s", Map[i]);
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		bool flag = false;
		for (int j = 0; j < M; j++)
			if (Map[i][j] == 'X')
				flag = true;
		if (!flag)
			cnt++;
	}
	ans = cnt;
	cnt = 0;
	for (int j = 0; j < M; j++) {
		bool flag = false;
		for (int i = 0; i < N; i++)
			if (Map[i][j] == 'X')
				flag = true;
		if (!flag)
			cnt++;
	}
	ans = max(ans, cnt);
	printf("%d\n", ans);
	return 0;
}