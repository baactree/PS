// =====================================================================================
// 
//       Filename:  4307.cpp
//        Created:  2017년 03월 03일 12시 47분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int l, n;
int arr[1000000];
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d%d", &l, &n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		int max_ans=-1;
		int min_ans=-1;
		for(int i=0;i<n;i++){
			max_ans=max(max_ans, max(arr[i]-0, l-arr[i]));
			min_ans=max(min_ans, min(arr[i]-0, l-arr[i]));
		}
		printf("%d %d\n", min_ans, max_ans);
	}
	return 0;
}


