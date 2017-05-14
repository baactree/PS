// =====================================================================================
// 
//       Filename:  1132.cpp
//        Created:  2017년 05월 14일 17시 31분 47초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long cnt[10];
bool top[10];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		top[str[0]-'A']=1;
		long long r=1;
		for(int j=str.size()-1;j>=0;j--){
			cnt[str[j]-'A']+=r;
			r*=10;
		}
	}
	int arr[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	long long ans=0;
	do{
		int zeroidx=0;
		for(int i=0;i<10;i++){
			if(arr[i]==0)
				zeroidx=i;
		}
		if(top[zeroidx])
			continue;
		long long now=0;
		for(int i=0;i<10;i++)
			now+=cnt[i]*arr[i];
		ans=max(now, ans);
	}while(next_permutation(arr, arr+10));
	printf("%lld\n", ans);
	return 0;
}

