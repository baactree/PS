// =====================================================================================
// 
//       Filename:  13302.cpp
//        Created:  2017-04-11 ¿ÀÀü 8:13:33
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================
#include <bits/stdc++.h> 
using namespace std;
int n, m;
int arr[100];
int cache[100][100];
int solve(int idx, int cnt){
	if(idx>=n)
		return 0;
	int &ret=cache[idx][cnt];
	if(ret!=-1)
		return ret;
	ret=0x3f3f3f3f;
	if(arr[idx])
		return ret=solve(idx+1, cnt);
	if(cnt>=3)
		ret=min(ret, solve(idx+1, cnt-3));
	ret=min(ret, solve(idx+1, cnt)+10000);
	ret=min(ret, solve(idx+3, cnt+1)+25000);
	ret=min(ret, solve(idx+5, cnt+2)+37000);
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int in;
		scanf("%d", &in);
		arr[in-1]=true;
	}
	memset(cache, -1, sizeof(cache));
	printf("%d\n", solve(0, 0));
	return 0;
}

