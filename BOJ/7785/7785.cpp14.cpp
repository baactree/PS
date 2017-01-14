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
int main(){
	int N;
	cin >> N;
	string name;
	string mode;
	for (int i = 0; i < N; i++){
		cin >> name >> mode;
		if (mode == "enter")
			arr[name] = 1;
		else
			arr.erase(name);
	}
	map<string, bool>::iterator itr;
	for (itr = arr.end(),itr--; itr != arr.begin(); itr--)
		cout<< itr->first<<'\n';
	cout << itr->first << '\n';
	return 0;
}