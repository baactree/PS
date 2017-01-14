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
char input[400000];
char output[1000100];
int main(){
	cin >> input;
	int len = strlen(input);
	int idx = 0;
	int now;
	for (int i = 0; i < len; i++){
		now = input[i]-48;
		output[idx + 2] = now % 2;
		now >>= 1;
		output[idx + 1] = now % 2;
		now >>= 1;
		output[idx] = now % 2;
		idx += 3;
	}
	int startidx = 0;
	while (startidx != idx - 1){
		if (output[startidx] != 0)
			break;
		startidx++;
	}
	for (int i = startidx; i < idx; i++)
		printf("%d", output[i]);
	printf("\n");
	return 0; 
}