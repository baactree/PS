// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 02월 24일 18시 48분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[3];
int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	n%=6;
 	arr[x]=1;
	bool flag=false;
	if(n%2==0)
		flag=true;
	for(int i=0;i<n;i++){
		if(flag){
			swap(arr[2], arr[1]);
			flag=false;
		}
		else{
			swap(arr[0], arr[1]);
			flag=true;

		}
	}
	int ans;
	for(int i=0;i<3;i++)
		if(arr[i])
			ans=i;
	printf("%d\n", ans);
	return 0;
}

