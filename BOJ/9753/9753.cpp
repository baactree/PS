// =====================================================================================
// 
//       Filename:  9753.cpp
//        Created:  2017년 03월 08일 19시 54분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
bool check[100001];
int main(){
	for(int i=2;i<=100000;i++){
		if(!check[i]){
			prime.push_back(i);
			check[i]=true;
			for(int j=i*2;j<=100000;j+=i){
				check[j]=true;
			}
		}
	}
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int k;
		scanf("%d", &k);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<prime.size();i++)
			for(int j=i+1;j<prime.size();j++){
				long long multi=(long long)prime[i]*prime[j];
				if(multi>=k){
					ans=min(ans, multi);
				}
			}
		printf("%lld\n", ans);
	}
	return 0;
}

