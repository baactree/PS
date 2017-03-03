// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 02월 21일 01시 04분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int ans=0;
	for(int i=0;i<n;i++){
		int le=lower_bound(arr, arr+n, arr[i])-arr;
		int ri=upper_bound(arr, arr+n, arr[i])-arr;
		if(le!=0&&ri!=n)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

