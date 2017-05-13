// =====================================================================================
// 
//       Filename:  1612.cpp
//        Created:  2017년 05월 13일 22시 10분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	if(n%2==0||n%5==0)
		printf("-1\n");
	else{
		int ans=0;
		int now=n;
		while(now){
			ans++;
			if(now%10==1){
				now/=10;
				continue;
			}
			for(int k=1;k<10;k++){
				int next=now+n*k;
				if(next%10==1){
					now=next/10;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

