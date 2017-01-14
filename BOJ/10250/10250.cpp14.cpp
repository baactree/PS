#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int main(void){
	int Case;
	cin >> Case;
	while (Case--) {
		int H, W, N;
		cin >> H >> W >> N;
		
		printf("%d\n", ((N-1)%H+1)*100+ ((N-1)/H + 1));
	}
	return 0;
}