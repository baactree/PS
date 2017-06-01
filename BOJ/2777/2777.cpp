// =====================================================================================
// 
//       Filename:  2777.cpp
//        Created:  2017년 06월 02일 01시 09분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[4]={2, 3, 5, 7};
int cnt[4];
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		if(n==1){
			printf("1\n");
			continue;
		}
		for(int i=0;i<4;i++){
			while(n%arr[i]==0){
				cnt[i]++;
				n/=arr[i];
			}
		}
		if(n!=1){
			printf("-1\n");
			continue;
		}
		int ans=cnt[2]+cnt[3];
		ans+=cnt[0]/3;
		cnt[0]%=3;
		ans+=cnt[1]/2;
		cnt[1]%=2;
		int t=min(cnt[0], cnt[1]);
		ans+=t;
		cnt[0]-=t;
		cnt[1]-=t;
		ans+=cnt[0]>0;
		ans+=cnt[1]>0;
		printf("%d\n", ans);
	}
	return 0;
}

