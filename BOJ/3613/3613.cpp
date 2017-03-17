// =====================================================================================
// 
//       Filename:  3613.cpp
//        Created:  2017년 03월 14일 17시 03분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
bool e(){
	if(str[0]>='A'&&str[0]<='Z')
		return true;
	if(str.find("__")!=string::npos)
		return true;
	if(str.find("_")!=string::npos){
		for(int i=0;i<str.size();i++)
			if(str[i]>='A'&&str[i]<='Z')
				return true;
	}
	if(str[0]=='_'||str[str.size()-1]=='_')
		return true;
	for(int i=0;i<str.size();i++)
		if(!(str[i]>='A'&&str[i]<='Z')&&!(str[i]>='a'&&str[i]<='z')&&str[i]!='_')
			return true;
	return false;
}
bool c(){
	for(int i=0;i<str.size();i++)
		if(str[i]>='A'&&str[i]<='Z')
			return false;
	return true;
}
void ctoj(){
	for(int i=0;i<str.size();i++)
		if(str[i]=='_')
			str[i+1]=str[i+1]-'a'+'A';
}
int main(){
	cin>>str;
	if(e()){
		printf("Error!\n");
		return 0;
	}
	if(c()){
		ctoj();
		for(int i=0;i<str.size();i++)
			if(str[i]=='_')
				continue;
			else
				printf("%c", str[i]);
		printf("\n");
		return 0;
	}
	for(int i=0;i<str.size();i++){
		if(str[i]>='A'&&str[i]<='Z'){
			printf("_%c", str[i]-'A'+'a');
		}
		else
			printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}

