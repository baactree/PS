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
LLU a, b;
LLU gcd(LLU a, LLU b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main(){
	cin >> a >> b;
	LLU ans = gcd(a, b);
	for (LLU i = 0; i < ans; i++)
		printf("1");
	printf("\n");
	return 0; 
}