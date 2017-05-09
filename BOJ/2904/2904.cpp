// =====================================================================================
// 
//       Filename:  2904.cpp
//        Created:  2017년 05월 09일 14시 27분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool p[1000000];
vector<int> prime;
int n;
map<int, int> mp[100];
map<int, int> m;
int main(){
	for(int i=2;i<1000000;i++){
		if(!p[i]){
			prime.push_back(i);
			for(int j=i+i;j<1000000;j+=i)
				p[j]=true;
		}
	}
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		int idx=0;
		while(in>1){
			while(in%prime[idx]==0){
				mp[i][prime[idx]]++;
				m[prime[idx]]++;
				in/=prime[idx];
			}
			idx++;
		}
	}
	int ans=1;
	int cnt=0;
	for(auto it=m.begin();it!=m.end();it++){
		int now=(it->first);
		int now_cnt=(it->second)/n;
		ans*=pow(now,now_cnt);
		for(int i=0;i<n;i++)
			cnt+=max(0, now_cnt-mp[i][now]);
	}
	printf("%d %d\n", ans, cnt);
	return 0;
}

