// =====================================================================================
// 
//       Filename:  2527.cpp
//        Created:  2017년 03월 29일 00시 12분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc=4;
	while(tc--){
		int a[4], b[4];
		for(int i=0;i<4;i++)
			scanf("%d", &a[i]);
		for(int i=0;i<4;i++)
			scanf("%d", &b[i]);
		char ans;
		if((b[2]<a[0]||a[2]<b[0])||(b[3]<a[1]||a[3]<b[1]))
			ans='d';
		else if(((a[2]==b[0])&&(a[1]==b[3]))||
				((a[2]==b[0])&&(a[3]==b[1]))||
				((a[0]==b[2])&&(a[1]==b[3]))||
				((a[0]==b[2])&&(a[3]==b[1]))
				)
			ans='c';
		else if(((a[1]==b[3])&&((a[0]<=b[0]&&b[0]<=a[2])||(b[0]<=a[0]&&a[0]<=b[2])))||
				((a[3]==b[1])&&((a[0]<=b[0]&&b[0]<=a[2])||(b[0]<=a[0]&&a[0]<=b[2])))||
				((a[0]==b[2])&&((a[1]<=b[1]&&b[1]<=a[3])||(b[1]<=a[1]&&a[1]<=b[3])))||
				((a[2]==b[0])&&((a[1]<=b[1]&&b[1]<=a[3])||(b[1]<=a[1]&&a[1]<=b[3])))
				)
			ans='b';
		else
			ans='a';
		printf("%c\n", ans);
	}
	return 0;
}

