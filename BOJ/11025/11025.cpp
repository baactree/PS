// =====================================================================================
// 
//       Filename:  11025.cpp
//        Created:  2017년 09월 28일 16시 25분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	int ans=1;
	for(int i=2;i<=n;i++)
		ans=((ans-1+m)%i+1);
	cout<<ans<<endl;
	return 0;
}

