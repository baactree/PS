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
int main(){
	int N, K;
	cin >> N >> K;
	int arr[100];
	for (int i = 0; i < K; i++)
		scanf("%d", &arr[i]);
	int ans = 0;
	int cnt = 0;
	int tap[101];
	for (int i = 0; i < K; i++){
		if (cnt < N){
			bool flag = true;
			for (int j = 1; j <= cnt; j++)
				if (tap[j] == arr[i]){
					flag = false;
					break;
				}
			if(flag) 
				tap[++cnt] = arr[i];
		}
		else{
			int _max = -1;
			int insult;
			for (int j = 1; j <= cnt; j++){
				if (tap[j] == arr[i]){
					ans--;
					insult = j;
					break;
				}
				for (int k = i + 1; k < K; k++){
					if (tap[j] == arr[k])
						if (_max < k){
							_max = k;
							insult = j;
							break;
						}
						else
							break;
					if (k == K - 1)
						if (_max < K){
							_max = K;
							insult = j;
							break;
						}
				}
			}
			ans++;
			tap[insult] = arr[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}