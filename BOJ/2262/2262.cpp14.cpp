#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#pragma warning (disable : 4996)

#define INF 0x3f3f3f3f
#define min(a,b)	( (a) < (b) ? (a) : (b) )

int N;
int A[301];
int d[301][301];
int win[301][301];

void init()
{
	memset(d , -1 , sizeof(d));

	scanf("%d" , &N);

	for (int i = 0; i < N; i++)
		scanf("%d" , &A[i]);

	for (int i = 0; i < N; i++)
	{
		win[i][i] = A[i];
		for (int j = i + 1; j < N; j++)
			win[i][j] = min(win[i][j - 1] , A[j]);
	}
}

int f(int l , int r)
{
	if (l == r)
		return 0;

	int &ret = d[l][r];
	if (ret != -1)
		return ret;

	ret = INF;

	for (int i = l; i < r; i++)
		ret = min(ret , f(l , i) + f(i + 1 , r) + abs(win[l][i] - win[i + 1][r]));

	return ret;
}

void solve()
{
	printf("%d\n" , f(0 , N - 1));
}

int main()
{
	init();

	solve();

	return 0;
}