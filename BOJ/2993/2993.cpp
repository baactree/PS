// =====================================================================================
// 
//       Filename:  2993.cpp
//        Created:  2017년 09월 10일 19시 04분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int main(){
	cin>>str;
	vector<string> vec;
	for(int i=1;i<str.size();i++){
		for(int j=i+1;j<str.size();j++){
			string a=string(str.begin(), str.begin()+i);
			string b=string(str.begin()+i, str.begin()+j);
			string c=string(str.begin()+j, str.end());
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			reverse(c.begin(), c.end());
			vec.push_back(a+b+c);
		}
	}
	sort(vec.begin(), vec.end());
	cout<<vec[0]<<endl;
	return 0;
}

