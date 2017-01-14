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
struct INFO{
	int age;
	char name[101];
};
bool cmp(const INFO& a, const INFO& b){
	return (a.age) < (b.age);
}
int N;
INFO info[100000];
int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		scanf("%d%s", &info[i].age, info[i].name);
	}
	stable_sort(&info[0], &info[0] + N,cmp);
	for (int i = 0; i < N; i++){
		printf("%d %s\n", info[i].age, info[i].name);
	}
	return 0; 
}