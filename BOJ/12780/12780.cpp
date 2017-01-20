// =====================================================================================
// 
//       Filename:  12780.cpp
//        Created:  2017년 01월 20일 19시 28분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string H, N;
vector<int> get_pi(string &N){
	int n=N.size();
	vector<int> pi(n, 0);
	int begin, matched;
	begin=1;
	matched=0;
	while(begin+matched<n){
		if(N[matched]==N[begin+matched]){
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
vector<int> kmp(string &H, string &N){
	int n=H.size();
	int m=N.size();
	vector<int> pi=get_pi(N);
	int begin, matched;
	begin=matched=0;
	vector<int> ret;
	while(begin<=n-m){
		if(matched<m&&H[begin+matched]==N[matched]){
			matched++;
			if(matched==m){
				ret.push_back(begin);
			}
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
int main(){
	cin>>H>>N;
	vector<int> ans=kmp(H, N);
	printf("%d\n", ans.size());
	return 0;
}

