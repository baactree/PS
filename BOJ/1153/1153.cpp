// =====================================================================================
// 
//       Filename:  1153.cpp
//        Created:  2017년 03월 10일 17시 35분 57초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool check[1000001];
vector<int> prime;
vector<int> ans;
void impossible(){
	printf("-1\n");
	exit(0);
}
int main(){
	for(int i=2;i<=1000000;i++){
		if(!check[i]){
			check[i]=true;
			prime.push_back(i);
			for(int j=i+i;j<=1000000;j+=i){
				check[j]=true;
			}
		}
	}
	int n;
	scanf("%d", &n);
	if(n<8)
		impossible();
	if(n&1){
		n-=2;
		ans.push_back(2);
		auto it = upper_bound(prime.begin(), prime.end(), n-4);
		if(it==prime.begin())
			impossible();
		int now=*(it-1);
		ans.push_back(now);
		n-=now;
		if(n<4||n&1)
			impossible();
		for(int i=0;prime[i]<=n;i++)
			for(int j=0;prime[i]+prime[j]<=n;j++){
				if(prime[i]+prime[j]==n){
					ans.push_back(prime[i]);
					ans.push_back(prime[j]);
					goto print;
				}
			}
	}
	else{
		auto it = upper_bound(prime.begin(), prime.end(), n-6);
		if(it==prime.begin())
			impossible();
		int now=*(it-1);
		if(now==2){
			n-=4;
			ans.push_back(2);
			ans.push_back(2);
		}
		else{
			n-=now;
			ans.push_back(now);
			it = upper_bound(prime.begin(), prime.end(), n-4);
			if(it==prime.begin())
				impossible();
			now = *(it-1);
			if(now==2)
				impossible();
			ans.push_back(now);
			n-=now;
		}
		for(int i=0;prime[i]<=n;i++)
			for(int j=0;prime[i]+prime[j]<=n;j++){
				if(prime[i]+prime[j]==n){
					ans.push_back(prime[i]);
					ans.push_back(prime[j]);
					goto print;
				}
			}
	}
print:
		for(int j=0;j<ans.size();j++)
			printf("%d ", ans[j]);
	return 0;
}

