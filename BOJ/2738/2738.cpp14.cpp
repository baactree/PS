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
int N, M;
int main(){
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &matrixA[i][j]);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){
			scanf("%d", &matrixB[i][j]);
			matrixB[i][j] += matrixA[i][j];
		}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
			printf("%d ", matrixB[i][j]);
		printf("\n");
	}

	return 0; 
}