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
vector<pair<int, int> > input;
int N;
int main(){
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++){
		scanf("%d%d", &a, &b);
		input.push_back(make_pair(b, a));
	}
	sort(input.begin(), input.end());
	for (int i = 0; i < N; i++)
		printf("%d %d\n", input[i].second, input[i].first);
	return 0; 
}