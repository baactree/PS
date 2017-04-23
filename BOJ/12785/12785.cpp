// =====================================================================================
// 
//       Filename:  12785.cpp
//        Created:  2017년 04월 21일 11시 44분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int w, h;
const int mod=1000007;
int cache[205][205];
int fx, fy;
int solve(int x, int y){
	if(x==fx&&y==fy)
		return 1;
	int &ret=cache[x][y];
	if(ret!=-1)
		return ret;
	ret=0;
	if(x!=w){
		ret+=solve(x+1, y);
		ret%=mod;
	}
	if(y!=h){
		ret+=solve(x, y+1);
		ret%=mod;
	}
	return ret;
}
int main(){
	scanf("%d%d%d%d", &w, &h, &fx, &fy);
	memset(cache, -1, sizeof(cache));
	int temp=solve(1, 1);
	int sx=fx;
	int sy=fy;
	fx=w;
	fy=h;
	memset(cache, -1, sizeof(cache));
	int ans=((long long)temp*solve(sx, sy))%mod;
	printf("%d\n", ans);
	return 0;
}

