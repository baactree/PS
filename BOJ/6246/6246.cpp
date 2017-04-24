
// =====================================================================================
// 
//       Filename:  6246.cpp
//        Created:  2017년 04월 24일 11시 14분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, q;
int arr[10005];
int main(){
	scanf("%d%d", &n, &q);
	for(int i=0;i<q;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		for(int j=a;j<=n;j+=b)
			arr[j]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(arr[i]==0)
			ans++;
	printf("%d\n", ans);
	return 0;
}

