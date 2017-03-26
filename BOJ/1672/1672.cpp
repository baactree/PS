// =====================================================================================
// 
//       Filename:  1672.cpp
//        Created:  2017년 03월 26일 18시 26분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
stack<char> st;
int n;
string str;
char mat[255][255];
int main(){
	mat['A']['A']='A';
	mat['A']['G']='C';
	mat['A']['C']='A';
	mat['A']['T']='G';
	
	mat['G']['A']='C';
	mat['G']['G']='G';
	mat['G']['C']='T';
	mat['G']['T']='A';
	
	mat['C']['A']='A';
	mat['C']['G']='T';
	mat['C']['C']='C';
	mat['C']['T']='G';

	mat['T']['A']='G';
	mat['T']['G']='A';
	mat['T']['C']='G';
	mat['T']['T']='T';

	cin>>n>>str;
	for(int i=0;i<n;i++)
		st.push(str[i]);
	while(true){
		if(st.size()==1){
			printf("%c\n", st.top());
			return 0;
		}
		char a=st.top();
		st.pop();
		char b=st.top();
		st.pop();
		st.push(mat[b][a]);
	}
	return 0;
}

