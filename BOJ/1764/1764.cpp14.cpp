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
#include <map>


using namespace std;
map<string, bool> arr;
vector<string> ans;
int main(){
	int N,M;
	cin >> N >> M;
	int cnt = 0;
	string in;
	for (int i = 0; i < N; i++){
		cin >> in;
		arr[in] = 1;
	}
	for (int i = 0; i < M; i++){
		cin >> in;
		if (arr.count(in) == 1){
			cnt++;
			ans.push_back(in);
		}
	}
	printf("%d\n", cnt);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
	return 0;
}