// =====================================================================================
// 
//       Filename:  1105.cpp
//        Created:  2017년 03월 02일 14시 08분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	string a, b;
	cin>>a>>b;
	string temp="";
	for(int i=0;i<b.size()-a.size();i++)
		temp+="0";
	a=temp+a;
	int ans=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==b[i]){
			if(a[i]=='8')
				ans++;
		}
		else
			break;
	}
	printf("%d\n", ans);
	return 0;
}

