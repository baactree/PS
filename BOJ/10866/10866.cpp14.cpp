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
deque<int> dq;
int main(){
	scanf("%d", &N);
	string command;
	int in;
	for (int i = 0; i < N; i++){
		cin >> command;
		if (command == "push_front"){
			scanf("%d", &in);
			dq.push_front(in);
		}
		else if (command == "push_back"){
			scanf("%d", &in);
			dq.push_back(in);
		}
		else if (command == "pop_front"){
			if (dq.empty())
				printf("-1\n");
			else{
				printf("%d\n", dq.front());
				dq.pop_front();
			}
		}
		else if (command == "pop_back"){
			if (dq.empty())
				printf("-1\n");
			else{
				printf("%d\n", dq.back());
				dq.pop_back();
			}
		}
		else if (command == "size"){
			printf("%d\n", dq.size());
		}
		else if (command == "empty"){
			printf("%d\n", dq.empty());
		}
		else if (command == "front"){
			if (dq.empty())
				printf("-1\n");
			else{
				printf("%d\n", dq.front());
			}
		}
		else if (command == "back"){
			if (dq.empty())
				printf("-1\n");
			else{
				printf("%d\n", dq.back());
			}
		}
	}
	return 0; 
}