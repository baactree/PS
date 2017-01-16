// =====================================================================================
// 
//       Filename:  9020.cpp
//        Created:  2017년 01월 16일 12시 13분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

vector<int> p;
bool isprime(int n){
	if(n==2)
		return true;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}
void solve(int n){
	int dist=1e9;
	int a, b;
	for(int i=0;i<p.size();i++){
		if(p[i]>n)
			break;
		for(int j=i;j<p.size();j++){
			if(p[j]>n)
				break;
			if(p[i]+p[j]==n){
				int nd=p[j]-p[i];
				if(dist>nd){
					dist=nd;
					a=p[i];
					b=p[j];
				}
				
			}
		}
	}
	printf("%d %d\n", a, b);
}
int main(){
	for(int i=2;i<=10000;i++)
		if(isprime(i))
			p.push_back(i);
	int Case;
	cin>>Case;
	while(Case--){
		int N;
		scanf("%d", &N);
		solve(N);
	}
	return 0;
}

