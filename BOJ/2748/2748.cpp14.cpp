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

int N;
unsigned long long int fibo[91];
int main(){
	fibo[0] = 0;
	fibo[1] = 1;
	cin >> N;
	for (int i = 2; i <= N; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	printf("%llu\n", fibo[N]);
	return 0; 
}