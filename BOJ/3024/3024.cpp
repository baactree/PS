// =====================================================================================
// 
//       Filename:  3024.cpp
//        Created:  2017년 08월 28일 23시 06분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
char mat[35][35];
int dx[4]={0, 1, 1, 1};
int dy[4]={1, 1, 0, -1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<n;
}
bool possi(int x, int y, int dir){
	int sx=x;
	int sy=y;
	char now=mat[x][y];
	int cnt=1;
	for(int i=0;i<2;i++){
		x=x+dx[dir];
		y=y+dy[dir];
		if(safe(x, y)&&mat[x][y]==now)
			cnt++;
	}
	if(cnt==3&&(!safe(sx-dx[dir], sy-dy[dir])||mat[sx-dx[dir]][sy-dy[dir]]!=now))
		return true;
	return false;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(mat[i][j]=='.')
				continue;
			for(int k=0;k<4;k++)
				if(possi(i, j, k))
					return !printf("%c\n", mat[i][j]);
		}
	printf("ongoing\n");
	return 0;
}

