// =====================================================================================
// 
//       Filename:  13419.cpp
//        Created:  2017년 03월 19일 18시 36분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		string str;
		cin>>str;
		str=str+str+str+str;
		vector<int> cnt(26, 0);
		string a, b;
		a=b="";
		for(int i=0;i<str.size();i+=2){
			if(cnt[str[i]-'A']!=0){
				break;
			}
			else{
				a+=str[i];
				cnt[str[i]-'A']=1;
			}
		}
		cnt=vector<int>(26, 0);
		for(int i=1;i<str.size();i+=2){
			if(cnt[str[i]-'A']!=0){
				break;
			}
			else{
				b+=str[i];
				cnt[str[i]-'A']=1;
			}
		}
		cout<<a<<'\n'<<b<<'\n';
	}
	return 0;
}

