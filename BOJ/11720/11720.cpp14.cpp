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
char input[101];
int main(){
	cin >> N;
	scanf("%s", input);
	int ans = 0;
	for (int i = N-1; i >= 0; i--){
		ans += input[i]-48;
	}
	printf("%d\n", ans);
	return 0; 
}