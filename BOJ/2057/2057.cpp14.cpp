#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <deque>
#include <stack>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
typedef unsigned long long LLU;
LLU fact[20];
LLU N;
bool search(int idx, LLU sum) {
	if (sum == N)
		return true;
	if (sum > N)
		return false;
	if (idx == 20)
		return false;
	if (search(idx + 1, sum + fact[idx]) || search(idx + 1, sum))
		return true;
	return false;
}
int main() {
	fact[0] = 1;
	for (int i = 1; i < 20; i++)
		fact[i] = fact[i - 1] * i;
	cin >> N;
	if (N == 0) {
		printf("NO\n");
		return 0;
	}
	if (search(0, 0))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}