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
int lotto[50];
int k;
int pick[6];
int idx;
void search(int index){
	if (idx == 6){
		for (int i = 0; i < idx; i++){
			printf("%d", pick[i]);
			if (i != idx - 1)
				printf(" ");
		}
		printf("\n");
		return;
	}
	if (index == k)
		return;
	for (int i = index; i < k; i++){
		pick[idx++] = lotto[i];
		search(i + 1);
		idx--;
	}
	
}
int main(){
	while (true){
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
			scanf("%d", &lotto[i]);
		idx = 0;
		search(0);
		printf("\n"); 
	}
	return 0; 
}