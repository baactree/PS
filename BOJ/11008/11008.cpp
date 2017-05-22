// =====================================================================================
// 
//       Filename:  11008.cpp
//        Created:  2017년 05월 22일 17시 20분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int find(const string &a, const string &b){
	int ret=0;
	for(int i=0;i+b.size()<=a.size();i++){
		bool flag=false;
		for(int j=0;j<b.size();j++){
			if(a[i+j]!=b[j])
				flag=true;
		}
		if(!flag){
			ret++;
			i+=b.size()-1;
		}
	}
	return ret;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		string h, s;
		cin>>h>>s;
		int cnt=find(h, s);
		printf("%d\n", h.size()-cnt*s.size()+cnt);
	}
	return 0;
}

