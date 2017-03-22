// =====================================================================================
// 
//       Filename:  2243.cpp
//        Created:  2017년 03월 22일 18시 08분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int candy[1000005];
int sq[1005];
int sz=1000;
int n;
int query(int x){
	int ret=0;
	int sum=0;
	while(true){
		if(sum+sq[ret]>=x)
			break;
		else{
			sum+=sq[ret];
			ret++;
		}
	}
	x-=sum;
	sum=0;
	for(int i=ret*sz;;i++){
		if(sum+candy[i]>=x)
			return i;
		else
			sum+=candy[i];
	}
	return 0;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d", &a);
		if(a==1){
			int b;
			scanf("%d", &b);
			int now=query(b);
			printf("%d\n", now);
			candy[now]--;
			sq[now/sz]--;
		
		}
		else{
			int b, c;
			scanf("%d%d", &b, &c);
			candy[b]+=c;
			sq[b/sz]+=c;
		}
	}
	return 0;
}

