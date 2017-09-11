// =====================================================================================
// 
//       Filename:  2784.cpp
//        Created:  2017년 09월 11일 22시 30분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str[6];
bool possi(){
	char mat[3][3];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			mat[i][j]=str[i][j];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(str[i+3][j]!=mat[j][i])
				return false;
	return true;
}
int main(){
	for(int i=0;i<6;i++)
		cin>>str[i];
	sort(str, str+6);
	do{
		if(possi()){
			for(int i=0;i<3;i++)
				cout<<str[i]<<endl;
			return 0;
		}
	}while(next_permutation(str, str+6));
	printf("0\n");
	return 0;
}

