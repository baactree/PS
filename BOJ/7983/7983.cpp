// =====================================================================================
// 
//       Filename:  7983.cpp
//        Created:  2017년 06월 04일 17시 58분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[1000000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].second, &arr[i].first);
	sort(arr, arr+n);
	int now=1e9;
	for(int i=n-1;i>=0;i--){
		if(now<=arr[i].first){
			now-=arr[i].second;
		}
		else
			now=arr[i].first-arr[i].second;
	}
	printf("%d\n", now);
	return 0;
}

