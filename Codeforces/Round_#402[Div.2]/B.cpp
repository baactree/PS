// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 03월 02일 15시 16분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
string str;
int main(){
	cin>>str>>k;
	n=stoi(str);
	int t=1;
	for(int i=0;i<k;i++)
		t*=10;
	if(t>n){
		printf("%d\n", str.size()-1);
	}
	else{
		int ans=0;
		for(int i=str.size()-1;i>=0;i--){
			if(k==0)
				break;
			if(str[i]=='0'){
				k--;
				continue;
			}
			ans++;
		}
		if(k>0)
			printf("%d\n", str.size()-1);
		else
			printf("%d\n", ans);
	}
	return 0;
}

