// =====================================================================================
// 
//       Filename:  1041.cpp
//        Created:  2017년 04월 21일 16시 59분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long int n;
int arr[6];
int main(){
	scanf("%lld", &n);
	for(int i=0;i<6;i++)
		scanf("%d", &arr[i]);
	if(n==1){
		int ans=0;
		for(int i=0;i<6;i++)
			ans+=arr[i];
		ans-=*max_element(arr, arr+6);
		printf("%d\n", ans);
		return 0;
	}
	vector<int> type3;
	vector<int> type2;
	type3.push_back(arr[0]+arr[1]+arr[3]);
	type3.push_back(arr[0]+arr[1]+arr[2]);
	type3.push_back(arr[0]+arr[4]+arr[3]);
	type3.push_back(arr[0]+arr[4]+arr[2]);
	type3.push_back(arr[5]+arr[1]+arr[3]);
	type3.push_back(arr[5]+arr[1]+arr[2]);
	type3.push_back(arr[4]+arr[5]+arr[3]);
	type3.push_back(arr[4]+arr[5]+arr[2]);

	type2.push_back(arr[0]+arr[1]);
	type2.push_back(arr[0]+arr[3]);
	type2.push_back(arr[0]+arr[2]);
	type2.push_back(arr[0]+arr[4]);
	type2.push_back(arr[1]+arr[3]);
	type2.push_back(arr[1]+arr[2]);
	type2.push_back(arr[1]+arr[5]);
	type2.push_back(arr[5]+arr[2]);
	type2.push_back(arr[5]+arr[3]);
	type2.push_back(arr[5]+arr[4]);
	type2.push_back(arr[4]+arr[2]);
	type2.push_back(arr[4]+arr[3]);
	long long int ans=0;
	//3면이 보이는 주사위
	ans+=4*(*min_element(type3.begin(), type3.end()));
	//2면이 보이는 주사위
	ans+=(4*(n-1)+4*(n-2))*(*min_element(type2.begin(), type2.end()));
	//1면이 보이는 주사위
	ans+=(4*(n-1)*(n-2)+(n-2)*(n-2))*(*min_element(arr, arr+6));
	printf("%lld\n", ans);
	return 0;
}

