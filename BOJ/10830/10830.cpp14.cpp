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
typedef unsigned long long int LLU;
int matrixA[5][5];
int ans[5][5];
int temp[5][5];
LLU N,B;
void multi(int A[][5], int B[][5], int C[][5]){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			int sum = 0;
			for (int k = 0; k < N; k++)
				sum = (sum + (A[i][k] * B[k][j]) % 1000) % 1000;
			C[i][j] = sum;
		}
}
void pow(LLU b){
	if (b == 1){
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans[i][j] = matrixA[i][j];
		return;
	}
	if (b % 2==0){
		pow(b / 2);
		multi(ans, ans, temp);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans[i][j] = temp[i][j];
		return;
	}
	pow(b - 1);
	multi(ans, matrixA, temp);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans[i][j] = temp[i][j];
	return;
}

int main(){
	cin >> N >> B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &matrixA[i][j]);
	pow(B);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			printf("%d ", ans[i][j]%1000);
		printf("\n");
	}
	return 0; 
}