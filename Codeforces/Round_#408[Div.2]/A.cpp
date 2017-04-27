// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 04월 25일 22시 18분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int arr[101];
int main(){
	scanf("%d%d%d", &n, &m, &k);
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		scanf("%d", &arr[i]);
		if(arr[i]&&arr[i]<=k){
			ans=min(ans, abs(i-m)*10);
		}
	}
	printf("%d\n", ans);
	return 0;
}

