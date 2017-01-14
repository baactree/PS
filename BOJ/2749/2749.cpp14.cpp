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
#define X 1500000
unsigned long long int N;
unsigned long long int fibo[1500000];
int main(){
	fibo[0] = 0;
	fibo[1] = 1;
	cin >> N;
	N %= X;
	for (int i = 2; i <= N; i++){
		fibo[i] = (fibo[i-1] + fibo[i-2]) % 1000000;
	}
	printf("%d\n", fibo[N]);
	return 0; 
}