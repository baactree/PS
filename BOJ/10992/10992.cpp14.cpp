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
int main(){
	int N;
	cin >> N;
	int block = N - 1;
	for (int i = 1; i <= N; i++){
		for (int j = 0; j < block; j++)
			printf(" ");
		printf("*");
		if (i == 1){
			printf("\n");
			block--;
			continue;
		}
		if (i == N){
			for (int k = 0; k < 2 * N - 2; k++)
				printf("*");
			printf("\n");
			break;
		}
		for (int k = 0; k < (i-2)*2+1; k++)
			printf(" ");
		printf("*\n");
		block--;
	}
	return 0; 
}