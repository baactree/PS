// =====================================================================================
// 
//       Filename:  13163.cpp
//        Created:  2017년 03월 15일 22시 03분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	scanf("%d\n", &tc);
	while(tc--){
		string name;
		getline(cin, name);
		printf("god");
		bool flag=false;
		for(int i=0;i<name.size();i++){
			if(name[i]==' '){
				flag=true;
				continue;
			}
			if(!flag)
				continue;
			printf("%c", name[i]);
		}
		printf("\n");
	}
	return 0;
}

