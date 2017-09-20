// =====================================================================================
// 
//       Filename:  3005.cpp
//        Created:  2017년 09월 19일 01시 33분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int r, c;
int trip[20][20][2];
int dx[2]={1, 0};
int dy[2]={0, 1};
bool safe(int x, int y){
	return x>=0&&x<r&&y>=0&&y<c;
}
char mat[25][25];
int main(){
	scanf("%d%d", &r, &c);
	for(int i=0;i<r;i++)
		scanf("%s", mat[i]);
	string ans(20, 'z');
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			for(int k=0;k<2;k++){
				if(mat[i][j]!='#'&&!trip[i][j][k]){
					string now="";
					int x=i;
					int y=j;
					while(safe(x, y)&&mat[x][y]!='#'){
						trip[x][y][k]=true;
						now+=mat[x][y];
						x=x+dx[k];
						y=y+dy[k];
					}
					if(now.size()>1)
						ans=min(ans, now);
				}
			}
	cout<<ans<<endl;
	return 0;
}

