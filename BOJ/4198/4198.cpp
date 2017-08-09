// =====================================================================================
// 
//       Filename:  4198.cpp
//        Created:  2017년 08월 09일 13시 20분 16초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[2000];
int cache1[2000], cache2[2000];
int solve1(int idx){
	int &ret=cache1[idx];
	if(ret!=-1)
		return ret;
	ret=1;
	for(int i=idx+1;i<n;i++)
		if(arr[i]>arr[idx])
			ret=max(ret, solve1(i)+1);
	return ret;
}
int solve2(int idx){
	int &ret=cache2[idx];
	if(ret!=-1)
		return ret;
	ret=1;
	for(int i=idx+1;i<n;i++)
		if(arr[i]<arr[idx])
			ret=max(ret, solve2(i)+1);
	return ret;
}
int main(){
	memset(cache1, -1, sizeof(cache1));
	memset(cache2, -1, sizeof(cache2));
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int ans=0;
	for(int i=0;i<n;i++){
		int a=solve1(i);
		int b=solve2(i);
		ans=max(ans, a+b-1);
	}
	printf("%d\n", ans);
	return 0;
}

