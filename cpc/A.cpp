// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 09월 20일 18시 35분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		string str;
		cin>>str;
		reverse(str.begin(), str.end());
		int sum=0;
		for(int i=0;i<str.size();i++){
			if(i&1){
				int now=str[i]-'0';
				now*=2;
				if(now>=10){
					now=now/10+now%10;
				}
				sum+=now;	
			}
			else{
				int now=str[i]-'0';
				sum+=now;
			}
		}
		printf("%s\n", sum%10==0?"T":"F");
	}
	return 0;
}

