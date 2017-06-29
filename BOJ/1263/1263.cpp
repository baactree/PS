// =====================================================================================
// 
//       Filename:  1263.cpp
//        Created:  2017년 06월 29일 10시 04분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[1000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].second, &arr[i].first);
	sort(arr, arr+n);
	int now=0x3f3f3f3f;
	for(int i=n-1;i>=0;i--){
		now=min(now, arr[i].first);
		now-=arr[i].second;
	}
	if(now<0)
		printf("-1\n");
	else
		printf("%d\n", now);
	return 0;
}

