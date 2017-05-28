// =====================================================================================
// 
//       Filename:  9196.cpp
//        Created:  2017년 05월 28일 10시 47분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct rect{
	int h, w;
	rect(){}
	rect(int h, int w):h(h), w(w){}
	bool operator < (const rect &rhs)const{
		int now=h*h+w*w;
		int there=rhs.h*rhs.h+rhs.w*rhs.w;
		if(now==there)
			return h<rhs.h;
		return now<there;
	}
};
int main(){
	while(true){
		int a, b;
		scanf("%d%d", &a, &b);
		if(a==0&&b==0)
			break;
		rect ans={400, 400};
		for(int i=1;i<=150;i++)
			for(int j=i+1;j<=150;j++){
				rect temp=rect(i, j);
				if(rect(a, b)<temp)
					ans=min(ans, temp);
			}
		printf("%d %d\n", ans.h, ans.w);
	}
	return 0;
}

