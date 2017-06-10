// =====================================================================================
// 
//       Filename:  11954.cpp
//        Created:  2017년 06월 10일 14시 21분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int indent;
int main(){
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='{'){
			printf("{");
			indent+=2;
			if(str[i+1]!='}'){
				printf("\n");
				for(int j=0;j<indent;j++)
					printf(" ");
			}
		}
		else if(str[i]=='}'){
			indent-=2;
			printf("\n");
			for(int j=0;j<indent;j++)
				printf(" ");
			printf("}");
		}
		else if(str[i]==','){
			printf(",\n");
			for(int j=0;j<indent;j++)
				printf(" ");
		}
		else{
			printf("%c", str[i]);
		}
	}
	return 0;
}

