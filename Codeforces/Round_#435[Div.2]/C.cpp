// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 09월 20일 00시 14분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, x;
int main(){
	scanf("%d%d", &n, &x);
	map<int, int> mp;
	for(int i=0;i<n;i++)
		mp[0]++;
	int r=0;
	int t=x;
	while(r<18){
		map<int, int> nmp;
		int now=x&1;
		x>>=1;
		int acnt, bcnt;
		acnt=bcnt=0;
		if(now){
			if((n/2)&1){
				bcnt=n/2;
				acnt=n-bcnt;
			}
			else{
				bcnt=n/2+1;
				acnt=n-bcnt;
			}
		}
		else{
			if((n/2)&1){
				bcnt=n/2+(r&1?1:-1);
				acnt=n-bcnt;
			}
			else{
				bcnt=n/2;
				acnt=n-bcnt;
			}
		}
		int cnt=r&1;
		for(auto it:mp){
			int a=it.first;
			int b=it.second;
			for(int i=0;i<b;i++){
				if(!acnt||(cnt&1&&bcnt)){
					nmp[(1<<r)+a]++;
					bcnt--;
				}
				else{
					nmp[a]++;
					acnt--;
				}
				cnt++;
			}
		}
		assert(acnt==0);
		assert(bcnt==0);
		r++;
		mp=nmp;
	}
	int sum=0;
	for(auto it:mp)
		sum^=it.first;
	if(mp.size()!=n||sum!=t){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(auto it:mp)
		printf("%d ", it.first);
	printf("\n");
	return 0;
}

