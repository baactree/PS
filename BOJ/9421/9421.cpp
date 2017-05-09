// =====================================================================================
// 
//       Filename:  9421.cpp
//        Created:  2017년 05월 08일 19시 40분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool prime[1000000];
vector<int> p;
int n;
bool possi(int x){
	set<int> s;
	while(x!=1){
		if(s.find(x)!=s.end())
			return false;
		s.insert(x);
		int next=0;
		while(x){
			int temp=x%10;
			next+=temp*temp;
			x/=10;
		}
		x=next;
	}
	return true;
}
int main(){
	for(int i=2;i<1000000;i++){
		if(!prime[i]){
			p.push_back(i);
			for(int j=i+i;j<1000000;j+=i)
				prime[j]=true;
		}
	}
	scanf("%d", &n);
	for(int i=0;i<p.size()&&p[i]<n;i++){
		if(possi(p[i]))
			printf("%d\n", p[i]);
	}
	return 0;
}

