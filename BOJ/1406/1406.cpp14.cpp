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
deque<int> ls;
deque<int> rs;
int N;
string str;
char order, in;
int main() {
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++)
		ls.push_back(str[i]);
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("\n%c", &order);
		switch (order) {
		case 'L':
			if (!ls.empty()) {
				rs.push_front(ls.back());
				ls.pop_back();
			}
			break;
		case 'D':
			if (!rs.empty()) {
				ls.push_back(rs.front());
				rs.pop_front();
			}
			break;
		case 'B':
			if (!ls.empty())
				ls.pop_back();
			break;
		case 'P':
			scanf(" %c", &in);
			ls.push_back(in);
			break;
		}
	}
	for (int i = 0; i < ls.size(); i++)
		printf("%c", ls[i]);
	for (int i = 0; i < rs.size(); i++)
		printf("%c", rs[i]);
	printf("\n");
	return 0;
}