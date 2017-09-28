// =====================================================================================
// 
//       Filename:  14465.cpp
//        Created:  2017년 09월 28일 16시 05분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k, b;
int arr[100005];
int main(){
	scanf("%d%d%d", &n, &k, &b);
	for(int i=0;i<b;i++){
		int x;
		scanf("%d", &x);
		arr[x]++;
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		if(arr[i])
			cnt++;
	}
	int ans=cnt;
	for(int i=k+1;i<=n;i++){
		if(arr[i-k])
			cnt--;
		if(arr[i])
			cnt++;
		ans=min(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}

