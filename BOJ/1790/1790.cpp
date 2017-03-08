// =====================================================================================
// 
//       Filename:  1790.cpp
//        Created:  2017년 03월 08일 21시 33분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
long long arr[8];
long long de[8];
int main(){
	scanf("%d%d", &n, &k);
	k--;
	int st=1;
	int cnt=1;
	arr[0]=9;
	de[0]=10;
	for(int i=1;i<8;i++){
		arr[i]=arr[i-1]*10;
		de[i]=de[i-1]*10;
	}
	for(int i=1;i<8;i++)
		arr[i]=arr[i-1]+arr[i]*(i+1);
	for(int i=7;i>=0;i--)
		if(k>=arr[i]){
			k-=arr[i];
			st=de[i];
			cnt+=i;
			break;
		}
	
	for(int i=st;i<=n;i++){
		if(i==de[cnt-1])
			cnt++;
		if(k<cnt){
			string now=to_string(i);
			printf("%c", now[k]);
			return 0;
		}
		else
			k-=cnt;
	}
	printf("-1\n");
	return 0;
}

