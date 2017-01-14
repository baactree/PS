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
int input[100];
int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main(){
	int Case;
	cin >> Case;
	while (Case--){
		int N;
		cin >> N;
		int ans = 0;
		for (int i = 0; i < N; i++){
			scanf("%d", &input[i]);
		}
		for (int i = 0; i < N; i++){
			for (int j = i + 1; j < N; j++){
				ans += gcd(input[i], input[j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0; 
}