#include "iostream"
#include "algorithm"
#include "stdio.h"
#include "string"
using namespace std;
string mat[4] = {  "ABCD" , "EFGH", "IJKL", "MNO." };
string input[4];
int cnt(int x,int y){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4;j++)
			if (mat[x][y] == input[i][j]){
				return abs(x - i) + abs(y - j);
			}
	return -1;
}
int main(){
	for (int i = 0; i < 4; i++)
		cin >> input[i];
	int ans = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++){
			if (i == 3 && j == 3)
				continue;
			ans += cnt(i,j);
		}
	printf("%d\n", ans);
	return 0;
}