// =====================================================================================
// 
//       Filename:  11674.cpp
//        Created:  2017년 09월 14일 18시 41분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int main(){
	cin>>str;
	int x, y;
	int r=1;
	x=y=0;
	for(int i=1;i<str.size();i++)
		r*=2;
	for(int i=0;i<str.size();i++){
		if(str[i]=='0'){
			
		}
		else if(str[i]=='1'){
			y+=r;
		}
		else if(str[i]=='2'){
			x+=r;
		}
		else if(str[i]=='3'){
			x+=r;
			y+=r;
		}
		r/=2;
	}
	printf("%d %d %d\n", str.size(), y, x);
	return 0;
}

