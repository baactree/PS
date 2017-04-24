// =====================================================================================
// 
//       Filename:  12840.cpp
//        Created:  2017년 04월 25일 00시 06분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int h, m, s;
int now;
int tc;
const int mod=24*60*60;
int main(){
	scanf("%d%d%d", &h, &m, &s);
	now=h*(60*60)+m*60+s;
	scanf("%d", &tc);
	while(tc--){
		int t, c;
		scanf("%d", &t);
		if(t==1){
			scanf("%d", &c);
			now=(now+c)%mod;
		}
		else if(t==2){
			scanf("%d", &c);
			now=(now-c%mod+mod)%mod;
		}
		else{
			int temp=now;
			int nh=temp/(60*60);
			temp%=60*60;
			int nm=temp/60;
			printf("%d %d %d\n", nh, nm, temp%60);
		}
	}
	return 0;
}

