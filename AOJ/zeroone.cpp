// =====================================================================================
// 
//       Filename:  zeroone.cpp
//        Created:  2017년 02월 21일 16시 09분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string arr;
int sum[1000001];
int main(){
	cin>>arr;
	for(int i=0;i<arr.size();i++){
		sum[i+1]=sum[i]+arr[i]-'0';
	}
	int q;
	scanf("%d", &q);
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		int now=sum[r+1]-sum[l];
		if(now==0||r-l+1==now)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

