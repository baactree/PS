// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 09월 17일 21시 48분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
char vowel[5]={'a', 'e', 'i', 'o', 'u'};
bool vv(char x){
	for(int i=0;i<5;i++)
		if(x==vowel[i])
			return true;
	return false;
}
int main(){
	cin>>str;
	int cnt=0;
	string ans="";
	set<char> s;
	for(int i=0;i<str.size();i++){
		if(vv(str[i])){
			printf("%c", str[i]);
			cnt=0;
			s.clear();
		}
		else{
			cnt++;
			s.insert(str[i]);
			if(cnt>=3&&s.size()!=1){
				printf(" %c", str[i]);
				cnt=1;
				s.clear();
				s.insert(str[i]);
			}
			else{
				printf("%c", str[i]);
			}
		}
	}
	printf("\n");
	return 0;
}

