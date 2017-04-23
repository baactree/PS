// =====================================================================================
// 
//       Filename:  11648.cpp
//        Created:  2017년 04월 23일 19시 19분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	scanf("%d", &x);
	int cnt=0;
	while(to_string(x).size()>1){
		string temp=to_string(x);
		int next=1;
		for(int i=0;i<temp.size();i++)
			next*=temp[i]-'0';
		x=next;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}


