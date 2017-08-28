// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 08월 14일 15시 21분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[100];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int a, b;
	a=b=0;
	for(int i=0;i<n;i++){
		a+=arr[i];
		b+=min(8, a);
		a-=min(8, a);
		if(b>=k)
			return !printf("%d\n", i+1);
	}
	printf("-1\n");
	return 0;
}

