// =====================================================================================
// 
//       Filename:  10803.cpp
//        Created:  2017년 04월 28일 16시 10분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int cache[10005][105];
int solve(int n, int m){
	if(m>n)
		return solve(m, n);
	if(n==0||m==0)
		return 0;
	int &ret=cache[n][m];
	if(ret!=-1)
		return ret;
	ret=0x3f3f3f3f;
	if(n>=3*m)
		ret=min(ret, solve(n-m, m)+1);
	else{
		for(int i=1;i<m;i++)
			ret=min(ret, solve(n, i)+solve(n, m-i));
		for(int i=1;i<n;i++)
			ret=min(ret, solve(i, m)+solve(n-i, m));
	}
	ret=min(ret, n/m+solve(n%m, m));
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", solve(n, m));
	return 0;
}

