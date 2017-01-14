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

using namespace std;
int N, M;
int main(){
	cin >> N >> M;
	if (N >= 3){
		if (M >= 7)
			printf("%d\n", M - 2);
		else 
			printf("%d\n",min(4,M));
	}
	else if (N == 2) {
		printf("%d\n",min(4, (M + 1) / 2));
	}
	else if (N == 1)
		printf("1\n");
	return 0;
}
