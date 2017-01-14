#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <deque>
#include <stack>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
typedef unsigned long long LLU;
vector<pair<int, string> >arr;
int N;
string in;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> in;
		int len = in.length();
		arr.push_back(make_pair(len, in));
	}
	sort(arr.begin(), arr.end());
	int _size = arr.size();
	for (int i = 0; i < _size; i++) {
		if (i != 0 && arr[i].second != arr[i - 1].second) {
			cout << arr[i].second << '\n';
		}
		if (i == 0)
			cout << arr[i].second << '\n';
	}

	return 0;
}