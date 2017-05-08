// =====================================================================================
// 
//       Filename:  13423.cpp
//        Created:  2017년 05월 08일 19시 24분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000];
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+n);
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				int diff=arr[j]-arr[i];
				int idx=lower_bound(arr, arr+n, arr[j]+diff)-arr;
				if(idx!=n&&arr[idx]==arr[j]+diff)
					ans++;
			}
		printf("%d\n", ans);
	}
	return 0;
}

