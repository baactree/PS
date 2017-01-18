// =====================================================================================
// 
//       Filename:  12778.cpp
//        Created:  2017년 01월 18일 22시 15분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int Case;
	scanf("%d", &Case);
	while(Case--){
		int M;
		char mode[2];
		scanf("%d%s", &M, mode);
		if(mode[0]=='C'){
			for(int i=0;i<M;i++){
				char input[2];
				scanf("%s", input);
				printf("%d ", input[0]-'A'+1);
			}
		}
		else{
			for(int i=0;i<M;i++){
				int input;
				scanf("%d", &input);
				printf("%c ", input-1+'A');
			}
		}
		printf("\n");
	}
	return 0;
}

