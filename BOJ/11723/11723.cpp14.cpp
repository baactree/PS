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
	unsigned int S = 0;
	string command;
	char input[20];
	int N;
	cin >> N;
	int in;
	for (int i = 0; i < N; i++){
		scanf("%s", input);
		command = input;

		if (command == "add"){
			scanf("%d", &in);
			S = S | (1 << (in - 1));
		}
		else if (command == "remove"){
			scanf("%d", &in);
			S = S&(~(1 << (in - 1)));
		}
		else if (command == "check"){
			scanf("%d", &in);
			if (S&(1 << (in - 1)))
				printf("1\n");
			else
				printf("0\n");
		}
		else if (command == "toggle"){
			scanf("%d", &in);
			if (S&(1 << (in - 1))){
				S = S&(!(1 << (in - 1)));
			}
			else{
				S = S | (1 << (in - 1));
			}
		}
		else if (command == "all"){
			S = S | 0x000fffff;
		}
		else if (command == "empty"){
			S = 0;
		}
	}
	return 0; 
}