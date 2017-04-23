// =====================================================================================
// 
//       Filename:  5636.cpp
//        Created:  2017년 04월 23일 18시 57분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<string> p;
bool isprime(int x){
	if(x==2)
		return true;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}
int main(){
	for(int i=2;i<100000;i++)
		if(isprime(i))
			p.push_back(to_string(i));
	while(true){
		string str;
		cin>>str;
		if(str=="0")
			break;
		for(int i=p.size()-1;i>=0;i--)
			if(str.find(p[i])!=string::npos){
				cout<<p[i]<<'\n';
				break;
			}
	}
	return 0;
}

