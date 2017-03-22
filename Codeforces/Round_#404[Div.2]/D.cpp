// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 03월 21일 21시 10분 17초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
const ll mod = 1000000007;
long long _pow(long long a, long long b){
	if(b==0)
		return 1;
	long long temp=_pow(a, b/2);
	if(b&1)
		return (((temp*temp)%mod)*a)%mod;
	return (temp*temp)%mod;
}
ll f[200005];
int sum[200005];
int main(){
	f[0]=1;
	for(int i=1;i<=200000;i++)
		f[i]=(f[i-1]*i)%mod;
	cin>>str;
	for(int i=0;i<str.size();i++)
		sum[i+1]=sum[i]+(str[i]=='(');
	ll ans=0;
	for(int i=1;i<=str.size();i++){
		int x=sum[i];
		int y=(int)str.size()-sum[str.size()]-(i-x);
		if(str[i-1]==')'||y==0)
			continue;
		ans+=(((f[x+y-1]*_pow(f[x], mod-2))%mod)*_pow(f[y-1], mod-2))%mod;
		ans%=mod;
	}
	printf("%lld\n", ans);

	return 0;
}

