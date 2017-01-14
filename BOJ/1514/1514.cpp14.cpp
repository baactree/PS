#include <cstdio>
int d[101][10][10];
int turn[10] = {0,1,1,1,2,2,2,1,1,1};
char temp[111];
const int inf = 2000000000;
int abs(int x) {
    return x>0?x:-x;
}
int main() {
    int n;
    scanf("%d",&n);
    int a[100];
    scanf("%s",temp);
    for (int i=0; i<n; i++) {
        a[i] = temp[i] - '0';
    }
    int b[100];
    scanf("%s",temp);
    for (int i=0; i<n; i++) {
        b[i] = temp[i] - '0';
    }
    for (int i=0; i<100; i++) {
        for (int j=0; j<10; j++) {
            for (int k=0; k<10; k++) {
                d[i][j][k] = inf;
            }
        }
    }
    d[0][0][0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<10; j++) {
            for (int k=0; k<10; k++) {
                if (d[i][j][k] != inf) {
                    for (int x=0; x<10; x++) {
                        for (int y=0; y<10; y++) {
                            int l = (a[i]+j+x+y)%10;
                            int cost = turn[abs(l-b[i])];
                            cost += d[i][j][k]+turn[x]+turn[y];
                            if (cost < d[i+1][(k+x+y)%10][y]) {
                                d[i+1][(k+x+y)%10][y] = cost;
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = inf;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (d[n][i][j] < ans) {
                ans = d[n][i][j];
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}