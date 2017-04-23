// =====================================================================================
// 
//       Filename:  5211.cpp
//        Created:  2017년 04월 23일 21시 05분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char str[105];
int a, c;
int main(){
	scanf("%s", str);
	char *p=strtok(str, "|");
	char *last;
	while(p!=NULL){
		last=p;
		if(p[0]=='C'||p[0]=='F'||p[0]=='G')
			c++;
		else if(p[0]=='A'||p[0]=='D'||p[0]=='E')
			a++;
		p=strtok(NULL, "|");
	}
	if(a<c)
		printf("C-major\n");
	else if(c<a)
		printf("A-minor\n");
	else{
		int len=strlen(last);
		if(last[len-1]=='C'||last[len-1]=='F'||last[len-1]=='G')
			printf("C-major\n");
		else
			printf("A-minor\n");
	}
	return 0;
}

