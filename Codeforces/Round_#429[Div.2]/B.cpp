// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 09월 08일 03시 37분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000000];
typedef long long ll;
int main(){
	scanf("%d", &n);
	ll s=0;
	int cnt=0;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		s+=arr[i];
		if(arr[i]&1)
			cnt++;
	}
	if(s&1||cnt)
		return !printf("First\n");
	printf("Second\n");
	return 0;
}

