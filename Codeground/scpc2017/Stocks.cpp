// =====================================================================================
// 
//       Filename:  Stocks.cpp
//        Created:  2017년 07월 01일 00시 06분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200005];
int main(){
	int testcase;
	scanf("%d",&testcase);
	for(int tc=1;tc<=testcase;tc++){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int now=-1;
		int ans=0;
		for(int i=0;i<n;i++){
			if(ans&1){
				if(now==-1||now<arr[i]){
					now=arr[i];
					ans++;
				}
				else{
					now=arr[i];
				}
			}
			else{
				if(now==-1||now>arr[i]){
					now=arr[i];
					ans++;
				}
				else{
					now=arr[i];
				}
			}
		}
		ans=ans/2*2;
		printf("Case #%d\n",tc);
		printf("%d\n",ans);
	}
	return 0;
}

