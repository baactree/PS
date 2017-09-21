// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 09월 22일 00시 16분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;
int a, b;
int am[4][4];
int bm[4][4];
int mat[4][4];
int trip[4][4];
pair<int, int> score[100];
int main(){
	mat[3][2]=1;
	mat[2][1]=1;
	mat[1][3]=1;
	scanf("%lld%d%d", &k, &a, &b);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			scanf("%d", &am[i][j]);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			scanf("%d", &bm[i][j]);
	int t=0;
	int x, y;
	x=a;
	y=b;
	int tx, ty;
	tx=ty=0;
	memset(trip, -1, sizeof(trip));
	while(k--){
		assert(t<100);
		score[t]={tx, ty};
		trip[x][y]=t;
		tx+=mat[x][y];
		ty+=mat[y][x];
		int nextx, nexty;
		nextx=am[x][y];
		nexty=bm[x][y];
		t++;
		x=nextx;
		y=nexty;
		if(trip[x][y]!=-1)
			break;
	}
	if(k<0)
		return !printf("%d %d\n", tx, ty);
	int g, ga, gb;
	g=t-trip[x][y];
	ga=tx-score[trip[x][y]].first;
	gb=ty-score[trip[x][y]].second;
	assert(g!=0);
	ll ansx=tx+k/g*ga;
	ll ansy=ty+k/g*gb;
	k%=g;
	while(k--){
		ansx+=mat[x][y];
		ansy+=mat[y][x];
		int nextx, nexty;
		nextx=am[x][y];
		nexty=bm[x][y];
		x=nextx;
		y=nexty;
	}
	printf("%lld %lld\n", ansx, ansy);
	return 0;
}

