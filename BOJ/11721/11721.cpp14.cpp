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
	char input[101];
	scanf("%s", input);
	int len = strlen(input);
	for (int i = 0; i < len; i++){
		printf("%c", input[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
	return 0; 
}