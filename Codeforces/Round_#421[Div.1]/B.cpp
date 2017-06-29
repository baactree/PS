// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 06월 28일 00시 08분 52초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000000];
int tt[2000005];
int main(){
	scanf("%d", &n);
	int cnt=0;
	long long int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		if(arr[i]>i+1){
			sum+=arr[i]-(i+1);
			tt[arr[i]-(i+1)]++;
		}
		else{
			cnt++;
			sum+=i+1-arr[i];
		}
	}
	int ans=0;
	long long min_value=sum;
	for(int i=0;i<n;i++){
		cnt--;
		tt[i+arr[n-1-i]]++;
		cnt+=tt[i];
		sum+=cnt;
		sum-=(n-cnt-1);
		sum=sum-(n-arr[n-1-i])+arr[n-1-i]-1;
		if(min_value>sum){
			min_value=sum;
			ans=i+1;
		}
	}
	printf("%lld %d\n", min_value, ans);
	return 0;
}

