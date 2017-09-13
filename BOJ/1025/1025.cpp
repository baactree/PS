// =====================================================================================
// 
//       Filename:  1025.cpp
//        Created:  2017년 09월 13일 22시 33분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[10][10];
int n, m;
long long ans=-1;
bool possi(long long x){
	long long le=0;
	long long ri=1e5;
	long long mid;
	long long ret=-1;
	while(le<=ri){
		mid=(le+ri)/2;
		if(mid*mid>=x){
			ret=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	return ret*ret==x;
}
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
void calc(int x, int y, int dx, int dy){
	long long now=0;
	while(safe(x, y)){
		now=now*10+mat[x][y];
		if(possi(now))
			ans=max(ans, now);
		x+=dx;
		y+=dy;
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			scanf("%1d", &mat[i][j]);
			if(possi(mat[i][j])){
				ans=max(ans, (long long)mat[i][j]);
			}
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			for(int x=0;x<n;x++)
				for(int y=0;y<m;y++){
					if(x==i&&y==j)
						continue;
					int dx=x-i;
					int dy=y-j;
					calc(i, j, dx, dy);
				}
	printf("%lld\n", ans);
	return 0;
}

