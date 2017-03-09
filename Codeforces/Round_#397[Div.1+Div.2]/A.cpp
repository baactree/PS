// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 03월 09일 15시 25분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
string home;
string u, v;
int main(){
	scanf("%d", &n);
	cin>>home;
	u=home;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>v;
		u=string(v.begin(), v.begin()+3);
		v=string(v.begin()+5, v.end());
		if(v==home)
			cnt++;
		if(u==home)
			cnt--;
	}
	if(cnt==0)
		printf("home\n");
	else
		printf("contest\n");
	return 0;
}
