// =====================================================================================
// 
//       Filename:  2154.cpp
//        Created:  2017년 04월 28일 15시 52분 17초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str="";
int n;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		str+=to_string(i);
	printf("%d\n", str.find(to_string(n))+1);
	return 0;
}

