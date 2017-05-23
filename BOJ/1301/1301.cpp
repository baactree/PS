// =====================================================================================
// 
//       Filename:  1301.cpp
//        Created:  2017년 05월 23일 11시 12분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[5];
long long cache[6][6][11][11][11][11][11];
long long solve(int ppre, int pre, int a, int b, int c, int d, int e, int s){
	if(s==0)
		return 1;
	long long &ret=cache[ppre][pre][a][b][c][d][e];
	if(ret!=-1)
		return ret;
	ret=0;
	if(a>0&&ppre!=0&&pre!=0)
		ret+=solve(pre, 0, a-1, b, c, d, e, s-1);
	if(b>0&&ppre!=1&&pre!=1)
		ret+=solve(pre, 1, a, b-1, c, d, e, s-1);
	if(c>0&&ppre!=2&&pre!=2)
		ret+=solve(pre, 2, a, b, c-1, d, e, s-1);
	if(d>0&&ppre!=3&&pre!=3)
		ret+=solve(pre, 3, a, b, c, d-1, e, s-1);
	if(e>0&&ppre!=4&&pre!=4)
		ret+=solve(pre, 4, a, b, c, d, e-1, s-1);
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	printf("%lld\n", solve(5, 5, arr[0], arr[1], arr[2], arr[3], arr[4], sum));
	return 0;
}

