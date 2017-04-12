// =====================================================================================
// 
//       Filename:  5904.cpp
//        Created:  2017-04-12 ¿ÀÈÄ 1:35:40
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int len[30];
char solve(int idx, int k){
	if(idx==0)
		return k==1?'m':'o';
	if(k<=len[idx-1])
		return solve(idx-1, k);
	else if(k<=len[idx-1]+idx+3){
		int temp=k-len[idx-1];
		return temp==1?'m':'o';
	}
	else
		return solve(idx-1, k-len[idx-1]-(idx+3));
}
int main(){
	len[0]=3;
	scanf("%d", &n);
	for(int i=1;i<30;i++){
		int k=len[i-1]*2+i+3;
		if(k>1e9){
			break;
		}
		else
			len[i]=k;
	}
	int idx;
	for(int i=0;i<30;i++)
		if(n<=len[i]){
			idx=i;
			break;
		}
	printf("%c\n", solve(idx, n));
	return 0;
}

