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
int input;
bool output[10000000];
int main(){
	cin >> input; 
	int divide;
	int idx = 0;
	while (true){
		if (input == 1||input==0){
			output[idx++] = input;
			break;
		}
		if (input >= 0){
			output[idx++] = input%-2;
			input /= -2;
		}
		else{
			if (input % -2 != 0){
				divide = input / -2 + 1;
				output[idx++] = -2 * divide - input;
				input = divide;
			}
			else{
				output[idx++] = 0;
				input /= -2;
			}
		}
	}
	for (int i = idx - 1; i >= 0; i--){
		printf("%d", output[i]);
	}
	printf("\n");
	return 0; 
}