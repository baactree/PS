#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int N;
int A[500][500];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int DP[500][500];
 
 
int go(int x, int y){
    if (DP[x][y] != -1)
        return DP[x][y];
 
 
    int find_max = 1;
    for (int i = 0; i < 4; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N && A[x][y] < A[nextX][nextY]){
            find_max = max(find_max, 1 + go(nextX, nextY) );
        }
    }
    return DP[x][y] = find_max;
}
 
 
 
int main(){
    cin >> N;
     memset(DP,-1,sizeof(DP));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &A[i][j]);
        }
    }
 
    int ans = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            ans = max(ans, go(i, j));
        }
    }
    cout << ans;
 
 
    return 0;
}