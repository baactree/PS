#include <cstdio>
#include <queue>
using namespace std;
int arr[310][310];
int year;
int n, m;
 
void bfs(int a, int b, int chk[310][310])
{
    queue<pair<int, int>>q;
    q.push({ a, b });
    while (q.size())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (arr[x + 1][y] > 0 && chk[x + 1][y] == 0)
        {
            chk[x + 1][y] = 1;
            q.push({ x + 1, y });
        }
        if (arr[x - 1][y] > 0 && chk[x - 1][y] == 0)
        {
            chk[x - 1][y] = 1;
            q.push({ x - 1, y });
        }
        if (arr[x][y + 1] > 0 && chk[x][y + 1] == 0)
        {
            chk[x][y + 1] = 1;
            q.push({ x, y + 1 });
        }
        if (arr[x][y - 1] > 0 && chk[x][y - 1] == 0)
        {
            chk[x][y - 1] = 1;
            q.push({ x, y - 1 });
        }
    }
}
 
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
 
    while (1)
    {
        int island = 0;
        int chk[310][310] = { 0, };
        for (int i = 1; i < n-1; i++)
        {
            for (int j = 1; j < m-1; j++)
            {
                if (arr[i][j] > 0)
                {
                    if (chk[i][j] == 0)
                    {
                        island++;
                        if (island >= 2) break;
                        bfs(i, j, chk);
                    }
                    int num = 0;
                    if (chk[i + 1][j] == 0 && arr[i + 1][j] == 0) num++;
                    if (chk[i][j + 1] == 0 && arr[i][j + 1] == 0) num++;
                    if (chk[i - 1][j] == 0 && arr[i - 1][j] == 0) num++;
                    if (chk[i][j - 1] == 0 && arr[i][j - 1] == 0) num++;
                    if (num > arr[i][j]) num = arr[i][j];
 
                    arr[i][j] -= num;
                }
            }
            if (island >= 2) break;
        }
 
        if (island >= 2) break;
         if(island==0){
             year=0;
             break;
         }
        year++;
    }
 
    printf("%d\n", year);
}