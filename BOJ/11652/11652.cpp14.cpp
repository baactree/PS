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
int N;
struct store{
	long long num;
	long long cnt;
};
store in[1000000];
bool cmp(const store& a, const store& b){
	return a.num < b.num;
}
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%lld", &in[i].num);
		in[i].cnt = 1;
	}
	sort(&in[0], &in[0] + N, cmp);
	long long int Maxcnt = -1;
	long long int Minnum;
	for (int i = 1; i < N; i++){
		if (in[i].num == in[i - 1].num){
			in[i].cnt = in[i - 1].cnt + 1;
			if (Maxcnt < in[i].cnt){
				Maxcnt = in[i].cnt;
				Minnum = in[i].num;
			}
		}
	}
	printf("%lld\n", Minnum);
	return 0; 
}