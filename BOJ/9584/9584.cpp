// =====================================================================================
// 
//       Filename:  9584.cpp
//        Created:  2017년 05월 22일 13시 02분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int n;
bool possi(const string &a){
	for(int i=0;i<str.size();i++)
		if(str[i]=='*')
			continue;
		else if(str[i]!=a[i])
			return false;
	return true;
}
int main(){
	cin>>str>>n;
	vector<string> arr;
	for(int i=0;i<n;i++){
		string in;
		cin>>in;
		if(possi(in))
			arr.push_back(in);
	}
	cout<<arr.size()<<endl;
	for(auto a:arr)
		cout<<a<<'\n';
	return 0;
}

