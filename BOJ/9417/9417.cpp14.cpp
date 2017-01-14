#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;
vector<int>arr;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
char input[5000];
int main() {
	int Case;
	cin.getline(input, 5000);
	Case = 0;
	int len = strlen(input);
	for (int i = 0; i < len; i++) {
		Case *= 10;
		Case += input[i] - '0';
	}
	while (Case--) {
		arr.clear();
		cin.getline(input, 5000);
		int temp=0;
		int len = strlen(input);
		for (int i = 0; i < len; i++) {
			if (input[i] == ' ') {
				arr.push_back(temp);
				temp = 0;
				continue;
			}
			temp *= 10;
			temp += input[i] - '0';
			if (i == len - 1)
				arr.push_back(temp);
		}
		int ans = -1;
		for (int i = 0; i < arr.size(); i++)
			for (int j = i + 1; j < arr.size(); j++)
				ans = max(ans,gcd(arr[i], arr[j]));
		printf("%d\n", ans);
	}
	
	return 0;
}