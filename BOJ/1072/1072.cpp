// =====================================================================================
// 
//       Filename:  1072.cpp
//        Created:  2017년 01월 20일 18시 45분 16초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	long long X, Y;
	while(scanf("%lld%lld", &X, &Y)!=EOF){
		int z=Y*100/X;
		if(z>=99){
			printf("-1\n");
			continue;
		}
		long long le, ri, mid, ans;
		le=0;
		ri=0x3f3f3f3f3f3f3f3f;
		while(ri>=le){
			mid=(ri+le)/2;
			if(z!=(Y+mid)*100/(X+mid)){
				ans=mid;
				ri=mid-1;
			}
			else
				le=mid+1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

