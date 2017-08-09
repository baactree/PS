// =====================================================================================
// 
//       Filename:  1264.cpp
//        Created:  2017년 08월 10일 00시 47분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char vowel[10]={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
int main(){
	string str;
	while(true){
		getline(cin, str);
		if(str=="#")
			break;
		int cnt=0;
		for(int i=0;i<str.size();i++)
			for(int j=0;j<10;j++)
				if(str[i]==vowel[j])
					cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}

