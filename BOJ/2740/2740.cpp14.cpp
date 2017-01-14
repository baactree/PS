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
int matrixA[100][100];
int matrixB[100][100];
int ans[100][100];
int N, M,K;
int main(){
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &matrixA[i][j]);
	cin >> M >> K;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			scanf("%d", &matrixB[i][j]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < K; j++){
			int sum = 0;
			for (int k = 0; k < M; k++){
				sum += matrixA[i][k] * matrixB[k][j];
			}
			ans[i][j] = sum;
		}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < K; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0; 
}