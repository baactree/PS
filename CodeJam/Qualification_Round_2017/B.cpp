// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 04월 08일 14시 06분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B.in", "w", stdout);
	int tc;
	scanf("%d", &tc);
	for(int t=1;t<=tc;t++){
		string str;
		cin>>str;
		for(int i=str.size()-1;i>0;i--){
			if(str[i-1]>str[i]){
				for(int j=i;j<str.size();j++)
					str[j]='0';
				long long temp=stoll(str);
				temp--;
				str=to_string(temp);
			}
		}
		cout<<"Case #"<<t<<": "<<str<<"\n";
	}
	return 0;
}

