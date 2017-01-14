// =====================================================================================
// 
//       Filename:  11502.cpp
//        Created:  2017년 01월 14일 21시 24분 00초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int K;
vector<int> p;
bool isprime(int x){
	if (x==2)
		return true;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}
void solve(){
	for(auto a:p)
		for(auto b:p)
			for(auto c:p)
				if(a+b+c==K){
					printf("%d %d %d\n", a, b, c);
					return ;
				}
	return;
}
int main(){
	int Case;
	cin>>Case;
	for(int i=2;i<1000;i++)
		if(isprime(i))
			p.push_back(i);
	while(Case--){
		scanf("%d", &K);
		solve();
	}
	return 0;
}

