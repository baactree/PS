// =====================================================================================
// 
//       Filename:  14551.cpp
//        Created:  2017년 06월 03일 23시 13분 39초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int ans=1;
	for(int i=0;i<n;i++){
		if(arr[i]==0)
			continue;
		ans=(ans*arr[i])%m;	
	}
	printf("%d\n", ans%m);
	return 0;
}

