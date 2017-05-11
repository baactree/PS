// =====================================================================================
// 
//       Filename:  7575.cpp
//        Created:  2017년 05월 11일 19시 03분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int m[100];
int arr[100][1000];
vector<int> get_pi(const vector<int> &h){
	int n=h.size();
	vector<int> pi(n);
	int begin, matched;
	begin=1;
	matched=0;
	while(begin+matched<n){
		if(h[begin+matched]==h[matched]){
			matched++;
			pi[begin+matched-1]=matched;
		}
		else{
			if(matched==0)
				begin++;
			else{
				begin=begin-pi[matched-1]+matched;
				matched=pi[matched-1];
			}
		}
	}
	return pi;
}
bool cmp(int x, const vector<int> &h){
	int n=m[x];
	int m=h.size();
	vector<int> pi=get_pi(h);
	int begin, matched;
	begin=matched=0;
	bool ret=false;
	while(begin<=n-m){
		if(matched<m&&arr[x][begin+matched]==h[matched]){
			matched++;
			if(matched==m)
				ret=true;
		}
		else{
			if(matched==0)
				begin++;
			else{
				begin=begin-pi[matched-1]+matched;
				matched=pi[matched-1];
			}
		}
	}
	return ret;
}
bool possi(const vector<int> &h, const vector<int> &rh){
	for(int i=1;i<n;i++)
		if(!cmp(i, h)&&!cmp(i, rh))
			return false;
	return true;
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%d", &m[i]);
		for(int j=0;j<m[i];j++)
			scanf("%d", &arr[i][j]);
	}
	bool ans=false;
	for(int i=0;i+k-1<m[0];i++){
		vector<int> h;
		vector<int> rh;
		for(int j=0;j<k;j++)
			h.push_back(arr[0][i+j]);
		rh=h;
		reverse(rh.begin(), rh.end());
		if(possi(h, rh))
			ans=true;
	}
	printf("%s\n", ans?"YES":"NO");
	return 0;
}

