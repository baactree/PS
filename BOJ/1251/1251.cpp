// =====================================================================================
// 
//       Filename:  1251.cpp
//        Created:  2017년 03월 03일 13시 04분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<string> arr;
string str;
int main(){
	cin>>str;
	for(int i=1;i<str.size();i++)
		for(int j=i+1;j<str.size();j++){
			string a = string(str.begin(), str.begin()+i);
			string b = string(str.begin()+i, str.begin()+j);
			string c= string(str.begin()+j, str.end());
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			reverse(c.begin(), c.end());
			arr.push_back(a+b+c);
		}
	sort(arr.begin(), arr.end());
	cout<<arr[0]<<endl;
	return 0;
}

