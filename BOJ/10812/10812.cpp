// =====================================================================================
// 
//       Filename:  10812.cpp
//        Created:  2017년 03월 03일 13시 45분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[101];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		arr[i]=i;
	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		rotate(arr+a, arr+c, arr+b+1);
	}
	for(int i=1;i<=n;i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

