// =====================================================================================
// 
//       Filename:  10504.cpp
//        Created:  2017년 09월 14일 02시 01분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool possi(int x, int n){
	if(x&1)
		return n%x==0;
	return (n-x/2)%x==0; 
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		int n;
		scanf("%d", &n);
		bool flag=false;
		for(int i=2;i*(i+1)<=2*n;i++){
			if(possi(i, n)){
				flag=true;
				int st=-1;
				if(i&1)
					st=n/i-i/2;
				else
					st=(n-i/2)/i-i/2+1;
				printf("%d = %d", n, st++);
				for(int j=st;j<st+i-1;j++)
					printf(" + %d", j);
				printf("\n");
				break;
			}
		}
		if(!flag)
			printf("IMPOSSIBLE\n");
	}
	return 0;
}

