// =====================================================================================
// 
//       Filename:  13206.cpp
//        Created:  2017년 04월 28일 12시 57분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> p;
bool isprime(int x){
	if(x==2)
		return true;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}
int cnt[1005];
const int mod=1000000007;
long long _pow(int a, int b){
	if(b==0)
		return 1;
	long long temp=_pow(a, b/2);
	temp=(temp*temp)%mod;
	if(b&1)
		return (temp*a)%mod;
	return temp;
}
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	for(int i=2;i<=1000;i++)
		if(isprime(i))
			p.push_back(i);
	while(TestCase--){
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for(int i=0;i<n;i++){
			int in;
			scanf("%d", &in);
			for(int j=0;j<p.size();j++){
				if(in<p[j])
					break;
				int temp=0;
				while(in%p[j]==0){
					in/=p[j];
					temp++;
				}
				cnt[p[j]]=max(cnt[p[j]], temp);
			}
		}
		long long ans=1;
		for(int i=0;i<1005;i++){
			ans=ans * _pow(i, cnt[i]);
			ans%=mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

