// =====================================================================================
// 
//       Filename:  2116.cpp
//        Created:  2017년 05월 08일 17시 13분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Dice{
	int a, b, c, d, e, f;
};
int n;
Dice arr[10000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c, &arr[i].d, &arr[i].e, &arr[i].f);
	int ans=0;
	for(int i=1;i<=6;i++){
		int pre=i;
		int now=0;
		for(int j=0;j<n;j++){
			if(pre==arr[j].a){
				now+=max(max(arr[j].b, arr[j].c), max(arr[j].d, arr[j].e));
				pre=arr[j].f;
			}
			else if(pre==arr[j].b){
				now+=max(max(arr[j].a, arr[j].c), max(arr[j].f, arr[j].e));
				pre=arr[j].d;
			}
			else if(pre==arr[j].c){
				now+=max(max(arr[j].b, arr[j].a), max(arr[j].d, arr[j].f));
				pre=arr[j].e;
			}
			else if(pre==arr[j].d){
				now+=max(max(arr[j].a, arr[j].c), max(arr[j].f, arr[j].e));
				pre=arr[j].b;
			}
			else if(pre==arr[j].e){
				now+=max(max(arr[j].d, arr[j].b), max(arr[j].a, arr[j].f));
				pre=arr[j].c;
			}
			else if(pre==arr[j].f){
				now+=max(max(arr[j].b, arr[j].c), max(arr[j].d, arr[j].e));
				pre=arr[j].a;
			}
		}
		ans=max(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}

