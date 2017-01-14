#include <cstdio>
#include <algorithm>

char temp[1001];
char str[1001][1001];
int n;

void _swap(int a, int b){
	sprintf(temp, "%s", str[a]);
	sprintf(str[a], "%s", str[b]);
	sprintf(str[b], "%s", temp);
}

int str_Compare(int a, int b){
	int index = 0;
	while (str[a][index] != 0 || str[b][index] != 0){
		if (str[a][index] > str[b][index] || str[b][index] == 0){
			_swap(a, b);
			return -1;
		}
		else if (str[a][index] < str[b][index] || str[a][index] == 0){
			return 1;
		}
		index++;
	}
	// 두 문자열이 일치하면 0 리턴
	return 0;
}


int main(){

	scanf("%s", &str[0]);
	
	n = 0;
	while (str[0][n] != '\0'){
		n++;
	}

	for (int i = 1; i < n; i++){
		for (int j = 0; i + j < n; j++){
			str[i][j] = str[0][i + j];
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - 1; j++)
			str_Compare(j, j+1);
	}

	for (int i = 0; i < n; i++){
		printf("%s\n", str[i]);
	}


	return 0;
}