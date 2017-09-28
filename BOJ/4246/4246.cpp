// =====================================================================================
// 
//       Filename:  4246.cpp
//        Created:  2017년 09월 28일 16시 09분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n)){
		if(n==0)
			break;
		string str;
		cin>>str;
		vector<string> mat;
		for(int i=0;i<str.size();i+=n)
			mat.push_back(string(str.begin()+i, min(str.end(), str.begin()+i+n)));
		for(int i=0;i<mat.size();i++){
			if(i&1)
				reverse(mat[i].begin(), mat[i].end());
		}
		string ans="";
		for(int i=0;i<n;i++)
			for(int j=0;j<mat.size();j++)
				ans+=mat[j][i];
		cout<<ans<<'\n';
	}
	return 0;
}

