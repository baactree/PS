// =====================================================================================
// 
//       Filename:  3060.cpp
//        Created:  2017년 02월 21일 15시 22분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long n;
long long arr[6];
long long temp[6];
int main(){
	int Case;
	cin>>Case;
	while(Case--){
		scanf("%lld", &n);
		for(int i=0;i<6;i++)
			scanf("%lld", &arr[i]);
		int ans=1;
		while(true){
			long long sum=0;
			for(int i=0;i<6;i++)
				sum+=arr[i];
			if(sum>n)
				break;
			for(int i=0;i<6;i++)
				temp[i]=arr[(i+1)%6]+arr[(i+5)%6]+arr[(i+3)%6]+arr[i];
			for(int i=0;i<6;i++)
				arr[i]=temp[i];
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

