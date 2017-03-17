// =====================================================================================
// 
//       Filename:  1769.cpp
//        Created:  2017년 03월 17일 16시 13분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	string x;
	cin>>x;
	int n=0;
	int sum=0;
	while(x.size()>1){
		sum=0;
		for(int i=0;i<x.size();i++)
			sum+=x[i]-'0';
		x=to_string(sum);
		n++;
	}
	printf("%d\n", n);
	if(x=="0"||x=="3"||x=="6"||x=="9")
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

