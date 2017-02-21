// =====================================================================================
// 
//       Filename:  uri.cpp
//        Created:  2017년 02월 21일 16시 24분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int Case;
	cin>>Case;
	while(Case--){
		string str;
		cin>>str;
		for(int i=0;i<str.size();i++){
			if(i+2<str.size()&&str[i]=='%'&&str[i+1]=='2'){
				if(str[i+2]=='0'){
					printf(" ");
					goto next;
				}
				if(str[i+2]=='1'){
					printf("!");
					goto next;
				}
				if(str[i+2]=='4'){
					printf("$");
					goto next;
				}
				if(str[i+2]=='5'){
					printf("%%");
					goto next;
				}
				if(str[i+2]=='8'){
					printf("(");
					goto next;
				}
				if(str[i+2]=='9'){
					printf(")");
					goto next;
				}
				if(str[i+2]=='a'){
					printf("*");
					goto next;
				}
			}
			printf("%c", str[i]);
			continue;
			next:
				i+=2;
		}
		printf("\n");
	}
	return 0;
}

