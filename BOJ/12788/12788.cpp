// =====================================================================================
// 
//       Filename:  12788.cpp
//        Created:  2017년 03월 10일 18시 34분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int arr[1000];
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int sum=m*k;
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		if(sum<=0)
			break;
		sum-=arr[i];
		cnt++;
	}
	if(sum>0)
		printf("STRESS\n");
	else
		printf("%d\n", cnt);
	return 0;
}

