// =====================================================================================
// 
//       Filename:  3226.cpp
//        Created:  2017년 03월 04일 21시 20분 47초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	scanf("%d", &n);
	int ans=0;
	while(n--){
		int h, m, d;
		scanf("%d:%d %d", &h, &m, &d);
		if(h>=7&&h<19){
			if(h<18){
				ans+= d*10;
			}
			else{
				if(m+d>60){
					ans+=(60-m)*10+(d+m-60)*5;
				}
				else
					ans+=d*10;
			}
		}
		else{
			if(h==6&&m+d>60){
				ans+= (60-m)*5+(d+m-60)*10;
			}
			else
				ans+=d*5;
		}
	}
	printf("%d\n", ans);
	return 0;
}

