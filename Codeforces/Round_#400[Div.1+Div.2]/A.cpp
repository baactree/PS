// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 02월 25일 21시 50분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string a, b;
int n;
int main(){
	cin>>a>>b;
	scanf("%d", &n);
	cout<<a<<" "<<b<<endl;
	for(int i=0;i<n;i++){
		string sa, sb;
		cin>>sa>>sb;
		if(a==sa)
			a=sb;
		else
			b=sb;
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}

