// =====================================================================================
// 
//       Filename:  2810.cpp
//        Created:  2017년 04월 01일 17시 56분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string str;
	cin>>n>>str;
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt++;
		if(str[i]=='L')
			i++;
	}
	cnt++;
	printf("%d\n", min(n, cnt));
	return 0;
}

