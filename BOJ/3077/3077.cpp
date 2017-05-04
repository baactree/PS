// =====================================================================================
// 
//       Filename:  3077.cpp
//        Created:  2017년 05월 04일 22시 42분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
map<unsigned long long, int> mp;
string str[2500];
unsigned long long int get_hash(const string &s){
	unsigned long long int ret=0;
	for(int i=0;i<s.size();i++)
		ret=ret*10007+s[i];
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		string in;
		cin>>in;
		unsigned long long int h=get_hash(in);
		mp[h]=i;
	}
	for(int i=0;i<n;i++)
		cin>>str[i];
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			unsigned long long int q=get_hash(str[i]);
			unsigned long long int w=get_hash(str[j]);
			if(mp[q]<mp[w])
				ans++;
		}
	printf("%d/%d\n", ans, (n*(n-1))/2);
	return 0;
}

