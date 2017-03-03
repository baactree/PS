// =====================================================================================
// 
//       Filename:  2851.cpp
//        Created:  2017년 01월 18일 22시 33분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[10];
int ans=-0x3f3f3f3f;
int dist=0x3f3f3f3f;
int main(){
	for(int i=0;i<10;i++)
		scanf("%d", &arr[i]);
	for(int i=1;i<=10;i++)
		for(int j=0;j<1;j++){
			int score=0;
			for(int k=j;k<j+i;k++){
				score+=arr[k];
			}
			int temp=abs(100-score);
			if(temp<dist){
				dist=temp;
				ans=score;
			}
			else if(temp==dist&&ans<score){
				ans=score;
			}
		}
	printf("%d\n", ans);
	return 0;
}

