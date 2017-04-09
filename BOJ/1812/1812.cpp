// =====================================================================================
// 
//       Filename:  1812.cpp
//        Created:  2017년 04월 09일 16시 38분 09초
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
	int sum=0;
	int temp=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		sum+=arr[i];
		if(i&1)
			temp+=arr[i];
	}
	sum/=2;
	sum-=temp;
	printf("%d\n", sum);
	for(int i=0;i<n-1;i++){
		printf("%d\n", arr[i]-sum);
		sum=arr[i]-sum;
	}
	return 0;
}

