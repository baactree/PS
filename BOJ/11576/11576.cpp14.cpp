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
int A, B;
int input[25];
int output[10000000];
int m;
int main(){
	cin >> A >> B>>m;
	for (int i = 0; i < m; i++)
		scanf("%d", &input[i]);
	unsigned int sum = 0;
	int r = 1;
	for (int i = m - 1; i >= 0; i--){
		sum += r*input[i];
		r *= A;
	}
	int idx = 0;
	while (true){
		output[idx++] = sum%B;
		sum /= B;
		if (sum == 0)
			break;
	}
	for (int i = idx - 1; i >= 0; i--)
		printf("%d ", output[i]);
	return 0; 
}