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
#define X 1000000007
LLU matrix[2][2] = { { 1, 1 }, { 1, 0 } };
LLU ans[2][2];
LLU temp[2][2];
LLU N;
void multi(LLU A[][2], LLU B[][2], LLU C[][2]){
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++){
			LLU sum = 0;
			for (int k = 0; k < 2; k++)
				sum = (sum + (A[i][k] * B[k][j])%X)%X;
			C[i][j] = sum;
		}
}
void pow(LLU n){
	if (n == 1){
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				ans[i][j] = matrix[i][j];
		return;
	}
	if (n % 2 == 0){
		pow(n / 2); 
		multi(ans, ans, temp);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				ans[i][j] = temp[i][j];
		return;
	}
	pow(n - 1);
	multi(ans, matrix, temp);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			ans[i][j] = temp[i][j];
	return;
}
int main(){
	cin >> N;
	if (N == 0)
		printf("0\n");
	else{
		pow(N);
		printf("%d\n", (ans[0][1])%X);
	}
	return 0; 
}