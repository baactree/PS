// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 09월 15일 22시 03분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100];
int cache[100][100][2];
int solve(int le, int ri, int mode){
	if(arr[le]%2==0||arr[ri]%2==0)
		return 0;
	if(mode&&(ri-le+1)&1)
		return 1;
	int &ret=cache[le][ri][mode];
	if(ret!=-1)
		return ret;
	ret=false;
	if(mode){
		for(int k=le;k<ri;k++)
			ret|=((solve(le, k, 0)&&solve(k+1, ri, 1))||(solve(le, k, 1)&&solve(k+1, ri, 0)));
	}
	else{
		for(int k=le;k<ri;k++)
			ret|=((solve(le, k, 0)&&solve(k+1, ri, 0))||(solve(le, k, 1)&&solve(k+1, ri, 1)));
	}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("%s\n", solve(0,n-1,1)?"Yes":"No");
	return 0;
}

