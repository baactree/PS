// =====================================================================================
// 
//       Filename:  1138.cpp
//        Created:  2017년 02월 22일 15시 15분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10];
int ans[10];
bool possi(){
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<i;j++)
			if(ans[i]<ans[j])
				sum++;
		if(arr[ans[i]-1]!=sum)
			return false;
	}
	return true;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	for(int i=0;i<n;i++)
		ans[i]=i+1;
	do{
		if(possi())
			break;
	}
	while(next_permutation(ans, ans+n));
	for(int i=0;i<n;i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

