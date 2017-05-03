// =====================================================================================
// 
//       Filename:  4375.cpp
//        Created:  2017년 05월 03일 14시 49분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	while(scanf("%d", &n)!=EOF){
		int ans=0;
		int temp=n;
		while(temp){
			int now=temp%10;
			if(now!=1){
				int pick=0;
				for(int i=0;i<10;i++){
					int t=(n*i)%10;
					if((t+now)%10==1){
						pick=i;
						break;
					}
				}
				temp+=n*pick;
			}
			temp/=10;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

