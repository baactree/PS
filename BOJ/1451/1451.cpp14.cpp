#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long int LLU;
int N, M;
char Map[100][101];
LLU sum[100][100];
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		scanf("%s", Map[i]);
	}

	for (int i = 0; i < N; i++)
	{
		sum[i][0] = Map[i][0] - 48;
		for (int j = 1; j < M; j++)
			sum[i][j] = sum[i][j - 1] + Map[i][j] - 48;
	}
	for (int j = 0; j < M; j++)
		for (int i = 1; i < N; i++)
			sum[i][j] += sum[i - 1][j];
	LLU ans = 0;
	

	//세로 분할
	for (int i = 0; i < M - 2; i++)
		for (int j = i + 1; j < M - 1; j++)
		{
			LLU A, B, C;//좌,중,우
			A = sum[N - 1][i];
			B = sum[N - 1][j] - A;
			C = sum[N - 1][M - 1] - B - A;
			ans = max(ans, A*B*C);
		}
	//가로 분할
	for (int i = 0; i < N - 2; i++)
		for (int j = i + 1; j < N - 1; j++)
		{
			LLU A, B, C;//상 중 하
			A = sum[i][M - 1];
			B = sum[j][M - 1] - A;
			C = sum[N - 1][M - 1] - B - A;
			ans = max(ans, A*B*C);
		}
	//4가지 방법
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < M - 1; j++)
		{
			LLU A, B, C, D;//좌상,우상,좌하,우하
			A = sum[i][j];
			B = sum[i][M - 1] - A;
			C = sum[N - 1][j] - A;
			D = sum[N - 1][M - 1] - B - C - A;
			ans = max(ans, (A + B)*C*D);
			ans = max(ans, A*C*(B + D));
			ans = max(ans, A*B*(C + D));
			ans = max(ans, B*D*(A + C));
		}

	printf("%llu\n", ans);
	return 0;
}
