#include <bits/stdc++.h>
using namespace std;
char mat[10][11];
bool now[10][10];
char pick[10];
int n,m;
bool flag;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char p[4]={'U', 'D', 'L', 'R'};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
void solve(int idx){
    if(flag)
        return;
	queue<pair<int, int> > q;
    for(int i=1;i+1<n;i++)
        for(int j=1;j+1<m;j++)
            if(now[i][j])
                q.push({i, j});
    if(q.empty()){
        flag=true;
        for(int i=0;i<idx;i++)
            printf("%c",pick[i]);
		printf("\n");
        return;
    }
	if(idx==10)
		return;
	for(int i=0;i<4;i++){
		queue<pair<int, int> > nq=q;
		memset(now, 0, sizeof(now));
		while(!nq.empty()){
			int x=nq.front().first;
			int y=nq.front().second;
			nq.pop();
			while(safe(x+dx[i], y+dy[i])&&mat[x+dx[i]][y+dy[i]]!='#'){
				x+=dx[i];
				y+=dy[i];
			}
			now[x][y]=true;
		}
		pick[idx]=p[i];
		solve(idx+1);
	}
}
int main(){
    int TestCase;
    scanf("%d",&TestCase);
    while(TestCase--){
		memset(now, 0, sizeof(now));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",mat[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]=='.')
                    now[i][j]=true;
        flag=false;
        solve(0);
        if(!flag){
            printf("XHAE\n");
        }
    }
    return 0;
}
