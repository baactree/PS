// =====================================================================================
// 
//       Filename:  4606.cpp
//        Created:  2017년 09월 13일 22시 29분 47초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char a[7]={' ', '!', '$', '%', '(', ')', '*'};
string b[7]={"%20", "%21", "%24", "%25", "%28", "%29", "%2a"};
int main(){
	string str;
	while(true){
		getline(cin, str);
		if(str=="#")
			break;
		string out="";
		for(int i=0;i<str.size();i++){
			int idx=-1;
			for(int j=0;j<7;j++)
				if(str[i]==a[j])
					idx=j;
			if(idx!=-1)
				out+=b[idx];
			else
				out+=str[i];
		}
		cout<<out<<'\n';
	}
	
	return 0;
}

