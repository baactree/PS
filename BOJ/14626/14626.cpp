// =====================================================================================
// 
//       Filename:  14626.cpp
//        Created:  2017년 08월 11일 21시 39분 04초
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
	for(int j=0;j<10;j++){
		int sum=0;
		for(int i=0;i<str.size();i++)
			if(str[i]=='*'){
				if(i&1)
					sum+=j*3;
				else
					sum+=j;
			}
			else if(i&1)
				sum+=(str[i]-'0')*3;
			else
				sum+=str[i]-'0';
		if(sum%10==0)
			return !printf("%d\n", j);
	}
	return 0;
}

