// =====================================================================================
// 
//       Filename:  1106.cpp
//        Created:  2017년 09월 19일 00시 32분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, c;
pair<int, int> arr[20];
int cache[20][1005];
int solve(int idx, int cnt){
	if(cnt>=c)
		return 0;
	if(idx==n)
		return 0x3f3f3f3f;
	int &ret=cache[idx][cnt];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1, cnt);
	ret=min(ret, solve(idx, cnt+arr[idx].second)+arr[idx].first);
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &c, &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	printf("%d\n", solve(0, 0));
	return 0;
}

