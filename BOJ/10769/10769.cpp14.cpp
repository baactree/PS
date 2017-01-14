#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;
char arr[300];
int main() {
	int happy = 0;
	int sad = 0;
	cin.getline(arr, 300);
	int len = strlen(arr);
	for (int i = 0; i < len-2; i++) {
		if (arr[i] == ':'&&arr[i + 1] == '-')
			if (arr[i + 2] == ')')
				happy++;
			else if (arr[i + 2] == '(')
				sad++;
	}


	if (happy == 0 && sad == 0)
		printf("none\n");
	else if (happy == sad)
		printf("unsure\n");
	else if (happy > sad)
		printf("happy\n");
	else if(sad>happy)
		printf("sad\n");
	return 0;
}