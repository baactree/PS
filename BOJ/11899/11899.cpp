// =====================================================================================
// 
//       Filename:  11899.cpp
//        Created:  2017년 04월 08일 12시 51분 37초
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
	int cnt=0;
	int ans=0;
	for(int i=0;i<str.size();i++){
		if(str[i]==')'){
			if(cnt==0)
				ans++;
			else
				cnt--;
		}
		else{
			cnt++;
		}
	}
	printf("%d\n", ans+cnt);
	return 0;
}

