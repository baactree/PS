// =====================================================================================
// 
//       Filename:  1564.cpp
//        Created:  2017년 04월 23일 19시 37분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
long long int f=1;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		f*=i;
		while(f%10==0)
			f/=10;
		f%=1000000000;
	}
	string temp=to_string(f);
	cout<<string(temp.end()-5, temp.end())<<endl;
	return 0;
}

