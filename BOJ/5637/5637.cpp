// =====================================================================================
// 
//       Filename:  5637.cpp
//        Created:  2017년 03월 29일 19시 00분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int ans=0;
	string astr;
	while(true){
		string a;
		cin>>a;
		if(a=="E-N-D")
			break;
		int cnt=0;
		for(int i=0;i<a.size();i++){
			if(a[i]>='a'&&a[i]<='z')
				cnt++;
			if(a[i]>='A'&&a[i]<='Z')
				cnt++;
			if(a[i]=='-')
				cnt++;
		}
		if(ans<cnt){
			ans=cnt;
			astr=a;
		}
	}
	for(int i=0;i<astr.size();i++){
		if(astr[i]>='a'&&astr[i]<='z')
			printf("%c", astr[i]);
		if(astr[i]>='A'&&astr[i]<='Z')
			printf("%c", astr[i]-'A'+'a');
		if(astr[i]=='-')
			printf("%c", astr[i]);
	}
	return 0;
}

