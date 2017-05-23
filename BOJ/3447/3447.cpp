// =====================================================================================
// 
//       Filename:  3447.cpp
//        Created:  2017년 05월 23일 16시 47분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	while(getline(cin, str)){
		deque<int> dq;
		for(int i=0;i<str.size();i++){
			if(dq.size()<2)
				dq.push_back(str[i]);
			else if(str[i]=='G'){
				int q=dq.back();
				dq.pop_back();
				int w=dq.back();
				dq.pop_back();
				if(q=='U'&&w=='B')
					continue;
				dq.push_back(w);
				dq.push_back(q);
				dq.push_back('G');
			}
			else{
				dq.push_back(str[i]);
			}
		}
		for(int i=0;i<dq.size();i++)
			printf("%c", dq[i]);
		printf("\n");
	}
	return 0;
}

