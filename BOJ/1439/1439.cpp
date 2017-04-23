// =====================================================================================
// 
//       Filename:  1439.cpp
//        Created:  2017년 04월 21일 16시 26분 27초
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
	string temp=str;
	int ans1=0;
	for(int i=0;i<temp.size();i++){
		if(temp[i]=='0'){
			ans1++;
			for(;i<temp.size()&&temp[i]=='0';i++)
				temp[i]='1';
			i--;
		}
	}
	int ans2=0;
	temp=str;
	for(int i=0;i<temp.size();i++){
		if(temp[i]=='1'){
			ans2++;
			for(;i<temp.size()&&temp[i]=='1';i++)
				temp[i]='0';
			i--;
		}
	}
	printf("%d\n", min(ans1, ans2));
	return 0;
}

