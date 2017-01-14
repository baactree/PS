#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>
#include <queue>
using namespace std;
string boom;
string input;
deque<char> arr;
int main(void){
	cin >> input;
	cin >> boom;
	int len_input = input.length();
	int len_boom = boom.length();
	for (int i = 0; i < len_input; i++) {
		arr.push_back(input[i]);
		if (arr.size() >= len_boom) {
			int idx = arr.size();
			idx--;
			bool flag = true;
			for (int i = 0; i < len_boom; i++) {
				if (boom[len_boom - 1 - i] != arr[idx - i]) {
					flag = false;
					break;
				}
			}
			if (flag) 
				for (int i = 0; i < len_boom; i++)
					arr.pop_back();
		}
	}
	if (arr.empty())
		printf("FRULA");
	else
		for (int i = 0; i < arr.size(); i++)
			printf("%c", arr[i]);
	printf("\n");
	return 0;
}