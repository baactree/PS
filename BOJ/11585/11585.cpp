// =====================================================================================
// 
//       Filename:  11585.cpp
//        Created:  2017년 08월 29일 01시 26분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	return b?gcd(b, a%b):a;
}
vector<int> get_pi(const string &a){
	int n=a.size();
	vector<int> pi(n, 0);
	int begin, matched;
	begin=1;
	matched=0;
	while(begin+matched<n){
		if(a[begin+matched]==a[matched]){
			matched++;
			pi[begin+matched-1]=matched;
		}
		else{
			if(matched==0)
				begin++;
			else{
				begin=begin+matched-pi[matched-1];
				matched=pi[matched-1];
			}
		}
	}
	return pi;
}
int kmp(const string &a, const string &b){
	int n=a.size();
	int m=b.size();
	int ret=0;
	vector<int> pi=get_pi(b);
	int begin, matched;
	begin=matched=0;
	while(begin<n-m){
		if(matched<m&&a[begin+matched]==b[matched]){
			matched++;
			if(matched==m)
				ret++;
		}
		else{
			if(matched==0)
				begin++;
			else{
				begin=begin+matched-pi[matched-1];
				matched=pi[matched-1];
			}
		}
	}
	return ret;
}
int n;
string h, s;
int main(){
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		char in[2];
		scanf("%s", in);
		h+=in[0];
	}
	for(int i=0;i<n;i++){
		char in[2];
		scanf("%s", in);
		s+=in[0];
	}
	s=s+s;
	int q=kmp(s, h);
	int g=gcd(q, n);
	printf("%d/%d\n", q/g, n/g);
	return 0;
}

