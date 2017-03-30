// =====================================================================================
// 
//       Filename:  5893.cpp
//        Created:  2017년 03월 31일 02시 27분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	string a;
	string b;
	cin>>a;
	b=a+"0000";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string ans="";
	int carry=0;
	for(int i=0;i<a.size();i++){
		int now=a[i]-'0'+b[i]-'0'+carry;
		if(now>1){
			carry=1;
			ans+='0'+now-2;
		}
		else{
			carry=0;
			ans+='0'+now;
		}
	}
	for(int i=a.size();i<b.size();i++){
		int now=b[i]-'0'+carry;
		if(now>1){
			carry=1;
			ans+='0'+now-2;
		}
		else{
			carry=0;
			ans+='0'+now;
		}
	}
	if(carry>0)
		ans+='1';
	reverse(ans.begin(), ans.end());
	cout<<ans<<endl;
	return 0;
}

