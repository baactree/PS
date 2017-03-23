// =====================================================================================
// 
//       Filename:  2999.cpp
//        Created:  2017년 03월 23일 11시 34분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
char mat[100][100];
int r, c;
int main(){
	cin>>str;
	for(int i=str.size();i>=0;i--){
		for(int j=i;j>=0;j--){
			if(i*j==str.size()){
				r=j;
				c=i;
				break;
			}
		}
	}
	int idx=0;
	for(int i=0;i<c;i++)
		for(int j=0;j<r;j++)
			mat[j][i]=str[idx++];
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			printf("%c", mat[i][j]);
	printf("\n");
	return 0;
}

