// =====================================================================================
// 
//       Filename:  1080.cpp
//        Created:  2017년 03월 10일 18시 45분 39초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
string now[50];
string goal[50];
void flip(int x, int y){
	for(int i=x;i<min(n, x+3);i++)
		for(int j=y;j<min(m, y+3);j++){
			now[i][j]='1'-now[i][j]+'0';
		}
}
int solve(int idx){
	if(idx==(n-2)*m)
		return 0;
	int nx=idx/m;
	int ny=idx%m;
	if(ny==m-2)
		return solve((nx+1)*m);
	if(now[nx][ny]==goal[nx][ny])		
		return solve(idx+1);
	flip(nx, ny);
	return solve(idx+1)+1;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		cin>>now[i];
	for(int i=0;i<n;i++)
		cin>>goal[i];
	bool flag=false;
	for(int i=0;i<n;i++)
		if(now[i]!=goal[i])
			flag=true;
	if(!flag){
		printf("0\n");
		return 0;
	}
	if(n<3||m<3){
		printf("-1\n");
		return 0;
	}
	int ans=solve(0);
	flag=false;
	for(int i=0;i<n;i++)
		if(now[i]!=goal[i])
			flag=true;
	if(flag)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}

