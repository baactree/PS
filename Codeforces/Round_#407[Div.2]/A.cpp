// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 04월 02일 14시 50분 12초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[100000];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=ceil((double)arr[i]/k);
	}
	printf("%d\n", (int)(ceil(ans/2.)));
	return 0;
}

