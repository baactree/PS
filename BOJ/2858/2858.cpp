// =====================================================================================
// 
//       Filename:  2858.cpp
//        Created:  2017년 03월 19일 21시 58분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int r, b;
/*
 *  r=2(l+w)-4;
 *  b=l*w-2(l+w)+4;
 *  2l+2w=r+4
 *  lw - 2l - 2w = b-4;
 *  r+b=l*w;
 *  l=(r+b)/w;
 *  2l=r-2w+4;
 *  2(r+b)=rw-2w^2+4;
 */
int main(){
	scanf("%d%d", &r, &b);
	for(int i=1;i<=5000;i++){
		if(2*(r+b)==r*i-2*i*i+4*i&&(r+b)%i==0){
			int w=i;
			int l=(r+b)/w;
			if(l>w)
				swap(w, l);
			printf("%d %d\n", w, l);
			break;
		}
	}
	return 0;
}

