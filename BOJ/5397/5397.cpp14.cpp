#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>
#include <queue>
using namespace std;
deque<char> ls;
deque<char> rs;
string input;
int main(void) {
	int Case;
	cin >> Case;
	while (Case--) {
		cin >> input;
		int len = input.length();
		ls.clear();
		rs.clear();
		for (int i = 0; i < len; i++) {
			if (input[i] == '<') {
				if (!ls.empty()) {
					rs.push_front(ls.back());
					ls.pop_back();
				}
			}
			else if (input[i] == '>') {
				if (!rs.empty()) {
					ls.push_back(rs.front());
					rs.pop_front();
				}
			}
			else if (input[i] == '-') {
				if (!ls.empty()) {
					ls.pop_back();
				}
			}
			else {
				ls.push_back(input[i]);
			}
		}
		for (int i = 0; i < ls.size(); i++)
			printf("%c", ls[i]);
		for (int i = 0; i < rs.size(); i++)
			printf("%c", rs[i]);
		printf("\n");
	}
	return  0;
}