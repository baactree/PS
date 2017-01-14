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
	int korean;
	int Eng;
	int math;
	char name[101];
};
bool cmp(const INFO& a, const INFO& b){
	if (a.korean != b.korean)
		return a.korean > b.korean;
	if (a.Eng != b.Eng)
		return a.Eng < b.Eng;
	if (a.math != b.math)
		return a.math > b.math;
	string temp, temp2;
	temp = a.name;
	temp2 = b.name;
	return temp < temp2;
}
int N;
INFO info[100000];
int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		scanf("%s%d%d%d", info[i].name, &info[i].korean, &info[i].Eng, &info[i].math);
	}
	sort(&info[0], &info[0] + N, cmp);
	for (int i = 0; i < N; i++){
		printf("%s\n", info[i].name);
	}
	return 0; 
}