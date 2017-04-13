// =====================================================================================
// 
//       Filename:  6322.cpp
//        Created:  2017-04-12 ¿ÀÈÄ 12:10:35
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int cnt=1;
	while(true){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a==0&&b==0&&c==0)
			break;
		if(a<0){
			a=c*c-b*b;
			printf("Triangle #%d\n", cnt);
			if(a>0)
				printf("a = %.3lf\n", sqrt(a));
			else
				printf("Impossible.\n");
		}
		else if(b<0){
			b=c*c-a*a;
			printf("Triangle #%d\n", cnt);
			if(b>0)
				printf("b = %.3lf\n", sqrt(b));
			else
				printf("Impossible.\n");
		}
		else{
			c=a*a+b*b;
			printf("Triangle #%d\n", cnt);
			printf("c = %.3lf\n", sqrt(c));
		}
		printf("\n");
		cnt++;
	}
	return 0;
}

