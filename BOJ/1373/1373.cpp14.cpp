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
char input[1000001];
char output[400000];
int main(){
	cin >> input;
	int len = strlen(input);
	int idx = 0;
	int sum;
	for (int i = len - 1; i >= 0; i-=3){
		if (i < 3){
			int r = 1;
			sum = 0;
			while (i >= 0){
				sum += (input[i] - 48)*r;
				r <<= 1;
				i--;
			}
			output[idx++] = sum;
		}
		else{
			sum = input[i] - 48 + (input[i - 1] - 48) * 2 + (input[i - 2] - 48) * 4;
			output[idx++] = sum;
		}
	}
	for (int i = idx - 1; i >= 0; i--)
		printf("%d", output[i]);
	printf("\n");
	return 0; 
}