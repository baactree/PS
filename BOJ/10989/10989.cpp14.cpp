#include "bits/stdc++.h"

using namespace std;
int cnt[10001];
int N;
char buffer[131072];
int idx, nidx;
extern inline char read(){
	if (idx == nidx){
		nidx = fread(buffer, 1, 131072, stdin);
		idx = 0;
	}
	return buffer[idx++];
}
extern inline int readInt(){
	int sum = 0;
	char now = read();
	while (now != '\n'){
		sum *= 10;
		sum += now - 48;
		now = read();
	}
	return sum;
}
int main(){
	N = readInt();
	for (int i = 0; i < N; i++)
		cnt[readInt()]++;
    char str[6];
	for (int i = 0; i <= 10000; i++){
        sprintf(str,"%d",i);
		for (int j = 0; j < cnt[i]; j++)
			puts(str);
	}
	return 0; 
}