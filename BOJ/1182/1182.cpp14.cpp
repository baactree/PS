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
int N, S;
int group[20];
int search(int n, int sum,int pick){
	if (sum == S&&n==N&&pick!=0){
		return 1;
	}
	if (n == N)
		return 0;
	int ret = 0;
	ret = search(n + 1, sum + group[n],pick+1) + search(n + 1, sum,pick);
	return ret;
}
int main(){
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		scanf("%d", &group[i]); 
	printf("%d\n", search(0, 0,0));
	return 0; 
}