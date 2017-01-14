#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>
#include <queue>
using namespace std;
string in;
int main(void){
	int N;
	cin >> N;
	int idx,idx2;
	for (int i = 0; i < N; i++) {
		cin >> in;
		if (in == "KBS1")
			idx = i;
		else if (in == "KBS2")
			idx2 = i;
	}
	for (int i = 0; i < idx; i++)
		printf("1");
	for (int i = 0; i < idx; i++)
		printf("4");
	if (idx > idx2)
		idx2++;
	for (int i = 0; i < idx2; i++)
		printf("1");
	for (int i = 0; i < idx2-1; i++)
		printf("4");
	printf("\n");
	return 0;
}