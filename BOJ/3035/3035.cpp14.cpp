#include "iostream"
#include "algorithm"
using namespace std;
int main(){
	int R, C, N, M;
	cin >> R >> C >> N >> M;
	char input[50][51];
	for (int i = 0; i < R; i++)
		scanf("%s", input[i]);
	for (int i = 0; i < R; i++){
		for (int k2 = 0; k2 < N; k2++){
			for (int j = 0; j < C; j++){
				for (int k = 0; k < M; k++)
					printf("%c", input[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}