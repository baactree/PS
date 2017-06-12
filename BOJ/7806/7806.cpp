// =====================================================================================
// 
//       Filename:  7806.cpp
//        Created:  2017년 06월 12일 17시 00분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int cntn[33000];
int cntk[33000];
bool prime[33000];
vector<int> p;
int main(){
	for(int i=2;i<33000;i++){
		if(!prime[i]){
			p.push_back(i);
			for(int j=i+i;j<33000;j+=i)
				prime[j]=true;
		}
	}
	while(scanf("%d%d", &n, &k)!=EOF){
		memset(cntn, 0, sizeof(cntn));
		memset(cntk, 0, sizeof(cntk));
		for(int i=0;i<p.size();i++){
			while(k%p[i]==0){
				k/=p[i];
				cntk[i]++;
			}
		}
		for(int i=0;i<p.size();i++){
			int t=n;
			while(t){
				cntn[i]+=t/p[i];
				t/=p[i];
			}
		}
		int ans=1;
		for(int i=0;i<p.size();i++){
			int now=min(cntn[i], cntk[i]);
			for(int j=0;j<now;j++)
				ans*=p[i];
		}
		if(n>=k)
			ans*=k;
		printf("%d\n", ans);
	}
	return 0;
}

