// =====================================================================================
// 
//       Filename:  14654.cpp
//        Created:  2017년 08월 29일 01시 17분 45초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int a[300], b[300];
int calc(int x, int y){
	if(x==y)
		return 3;
	if(x==1)
		return y==3?1:2;
	if(x==2)
		return y==1?1:2;
	if(x==3)
		return y==2?1:2;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	for(int i=0;i<n;i++)
		scanf("%d", &b[i]);
	int ans=0;
	int cnt=0;
	int p=0;
	for(int i=0;i<n;i++){
		int g=calc(a[i], b[i]);
		if(g==1){
			if(p==1){
				cnt++;
			}
			else{
				cnt=1;
				p=1;
			}
		}
		else if(g==2){
			if(p==2){
				cnt++;
			}
			else{
				cnt=1;
				p=2;
			}
		}
		else{
			if(p==1){
				p=2;
				cnt=1;
			}
			else{
				p=1;
				cnt=1;
			}
		}
		ans=max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}

