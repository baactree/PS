// =====================================================================================
// 
//       Filename:  2790.cpp
//        Created:  2017년 04월 21일 16시 11분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[300000];
int p[300000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int temp=n;
	for(int i=0;i<n;i++){
		p[i]=arr[i]+temp;
		temp--;
	}
	int ans=0;
	int max_val=*max_element(p, p+n);
	for(int i=0;i<n;i++){
		if(arr[i]+n>=max_val)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

