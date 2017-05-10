// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 05월 05일 00시 09분 17초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char str[1000005];
long long cnt[1000005];
long long r[1000005];
const int mod=1000000007;
int main(){
	scanf("%s", str);
	cnt[1]=1;
	r[0]=1;
	for(int i=1;i<=1000000;i++)
		r[i]=(r[i-1]*2)%mod;
	for(int i=2;i<=1000000;i++)
		cnt[i]=(cnt[i-1]+r[i-1])%mod;
	int now=0;
	long long ans=0;
	for(int i=0;str[i];i++){
		if(str[i]=='a')
			now++;
		else{
			ans+=cnt[now];
			ans%=mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

