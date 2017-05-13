// =====================================================================================
// 
//       Filename:  11094.cpp
//        Created:  2017년 05월 13일 22시 07분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		string str;
		getline(cin, str);
		if(string(str.begin(), str.begin()+min((int)str.size(), 10))=="Simon says")
			cout<<string(str.begin()+10, str.end())<<'\n';
	}
	return 0;
}

