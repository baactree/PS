// =====================================================================================
// 
//       Filename:  1031.cpp
//        Created:  2017년 08월 09일 16시 47분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n, m;
int c[105][105];
int f[105][105];
int par[105];
int trip[105];
int flow(int s, int t){
	int ret=0;
	while(true){
		memset(trip, 0, sizeof(trip));
		trip[s]=true;
		queue<int> q;
		q.push(s);
		while(!q.empty()&&!trip[t]){
			int now=q.front();
			q.pop();
			for(int there=0;there<=t;there++){
				if(c[now][there]-f[now][there]&&!trip[there]){
					trip[there]=true;
					par[there]=now;
					q.push(there);
				}
			}
		}
		if(!trip[t])
			break;
		ret++;
		int now=t;
		while(now!=s){
			int p=par[now];
			f[p][now]++;
			f[now][p]--;
			now=p;
		}
	}
	return ret;
}
void calc(int x, int y, int s, int t){
	f[s][x]--;
	f[y][t]--;
	f[x][y]--;
	f[y][x]++;
	memset(trip, 0, sizeof(trip));
	trip[s]=true;
	queue<int> q;
	q.push(s);
	while(!q.empty()&&!trip[t]){
		int now=q.front();
		q.pop();
		for(int there=x;there<=t;there++){
			if(now==x&&there<=y)
				continue;
			if(c[now][there]-f[now][there]&&!trip[there]){
				trip[there]=true;
				par[there]=now;
				q.push(there);
			}
		}
	}
	if(!trip[t]){
		f[s][x]++;
		f[y][t]++;
		f[x][y]++;
		f[y][x]--;
		return;
	}
	int now=t;
	while(now!=s){
		int p=par[now];
		f[p][now]++;
		f[now][p]--;
		now=p;
	}
}
int main(){
	scanf("%d%d", &n, &m);
	int s, t;
	s=0;
	t=n+m+1;
	int a, b;
	a=b=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d", &x);
		c[s][i]=x;
		a+=x;
	}
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d", &x);
		c[i+n][t]=x;
		b+=x;
	}
	if(a!=b)
		return !printf("-1\n");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			c[i][j+n]=1;
	int k=flow(s, t);
	if(k!=a)
		return !printf("-1\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j+n]){
				calc(i, j+n, s, t);
			}
			printf("%d", f[i][j+n]);
		}
		printf("\n");
	}
	return 0;
}
