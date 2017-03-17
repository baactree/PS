// =====================================================================================
// 
//       Filename:  2346.cpp
//        Created:  2017년 03월 17일 20시 49분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int now=0;
	int cnt=n;
	while(true){
		printf("%d ", now+1);
		cnt--;
		if(cnt==0)
			break;
		int k=arr[now];
		arr[now]=0;
		if(k>0){
			while(k--){
				now=(now+1)%n;
				if(arr[now]==0)
					k++;
			}
		}
		else{
			k=-k;
			while(k--){
				now=(now-1+n)%n;
				if(arr[now]==0)
					k++;
			}
		}
	}
	return 0;
}

