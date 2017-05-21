// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 05월 21일 21시 18분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[300000];
const int mod=1e9+7;
int _pow(int a, int b){
	if(b==0)
		return 1;
	int temp=_pow(a, b/2);
	temp=((long long)temp*temp)%mod;
	if(b&1)
		return (temp*a)%mod;
	return temp;
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int sum=0;
	int ans=0;
	for(int i=1;i<n;i++){
		long long diff=arr[i]-arr[i-1];
		sum=(sum*2ll+(diff*(_pow(2, i)-1))%mod)%mod;
		ans=(ans+sum)%mod;
	}
	printf("%d\n", ans);
	return 0;
}

