// =====================================================================================
// 
//       Filename:  1014.cpp
//        Created:  2017년 03월 07일 01시 11분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[10][11];
int cache[100][1<<12];
int solve(int idx, int state){
	if(idx==n*m)
		return 0;
	int &ret=cache[idx][state];
	if(ret!=-1)
		return ret;
	int nx=idx/m;
	int ny=idx%m;
	if(mat[nx][ny]=='x')
		return ret=solve(idx+1,(state>>1));
	ret=solve(idx+1, state>>1);
	if(nx==0){
		if((state&(1<<m))==0){
			ret=max(ret, solve(idx+1, (state>>1)|(1<<m))+1);
		}
	}
	else if(ny==0){
		if((state&4)==0){
			ret=max(ret, solve(idx+1, (state>>1)|(1<<m))+1);
		}
	}
	else if(ny==m-1){
		if((state&1)==0&&(state&(1<<m))==0){
			ret=max(ret, solve(idx+1, (state>>1)|(1<<m))+1);
		}
	}
	else{
		if((state&(1<<m))==0&&(state&1)==0&&(state&4)==0)
			ret=max(ret, solve(idx+1, (state>>1)|(1<<m))+1);
	}
	return ret;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		memset(cache, -1, sizeof(cache));
		scanf("%d%d", &n, &m);
		for(int i=0;i<n;i++)
			scanf("%s", mat[i]);
		printf("%d\n",solve(0, 0));
	}
	return 0;
}

