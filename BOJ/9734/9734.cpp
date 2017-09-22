// =====================================================================================
// 
//       Filename:  9734.cpp
//        Created:  2017년 09월 22일 22시 36분 02초
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
int main(){
	string str;
	while(cin>>str){
		string a="";
		string b="";
		string c="";
		int cnt=0;
		for(int i=0;i<str.size();i++){
			if(str[i]=='.'){
				cnt++;
				continue;
			}
			if(str[i]=='('){
				cnt++;
				continue;
			}
			if(str[i]==')'){
				break;
			}
			if(cnt==0)
				a+=str[i];
			if(cnt==1)
				b+=str[i];
			if(cnt==2)
				c+=str[i];
		}
		int q=stoi(a+b+c)-stoi(a+b);
		int p=stoi(string(c.size(), '9')+string(b.size(), '0'));
		int g=gcd(p, q);
		cout<<str<<" = "<<q/g<<" / "<<p/g<<'\n';
	}
	return 0;
}

