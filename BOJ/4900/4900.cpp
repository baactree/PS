// =====================================================================================
// 
//       Filename:  4900.cpp
//        Created:  2017년 05월 29일 20시 30분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
map<string, int> mp;
string t[10]={"063", "010", "093", "079", "106", "103", "119", "011", "127", "107"};
int main(){
	mp["010"]=1;
	mp["079"]=3;
	mp["106"]=4;
	mp["063"]=0;
	mp["093"]=2;
	mp["103"]=5;
	mp["119"]=6;
	mp["011"]=7;
	mp["127"]=8;
	mp["107"]=9;
	while(true){
		cin>>str;
		if(str=="BYE")
			break;
		int idx=str.find("+");
		string le=string(str.begin(), str.begin()+idx);
		string ri=string(str.begin()+idx+1, str.end()-1);
		int a, b;
		a=b=0;
		for(int i=0;i<le.size();i+=3)
			a=a*10+mp[string(le.begin()+i, le.begin()+i+3)];
		for(int i=0;i<ri.size();i+=3)
			b=b*10+mp[string(ri.begin()+i, ri.begin()+i+3)];
		int c=a+b;
		string ans="";
		stack<string> st;
		while(c){
			st.push(t[c%10]);
			c/=10;
		}
		while(!st.empty()){
			ans+=st.top();
			st.pop();
		}
		cout<<le<<"+"<<ri<<"="<<ans<<endl;
	}
	return 0;
}

