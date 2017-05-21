// =====================================================================================
// 
//       Filename:  14581.cpp
//        Created:  2017년 05월 21일 13시 30분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string mat[3][3];
int main(){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			mat[i][j]="fan";
	cin>>mat[1][1];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<":"+mat[i][j]+":";
		cout<<endl;
	}
	return 0;
}

