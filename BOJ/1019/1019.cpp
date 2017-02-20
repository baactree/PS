// =====================================================================================
// 
//       Filename:  1019.cpp
//        Created:  2017년 02월 20일 17시 35분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[10][10];
ll arr2[10][10];
ll ans[10];
int main(){
	int N;
	scanf("%d", &N);
	for(int i=0;i<10;i++)
		arr[1][i]=arr2[1][i]=1;
	for(int i=2;i<10;i++){
		arr[i][0]=arr[i-1][0]+arr2[i-1][0]*9;
		for(int j=1;j<10;j++){
			arr[i][j]=arr[i-1][j]*10+pow(10, i-1);
		}
		for(int j=0;j<10;j++)
			arr2[i][j]=arr2[i-1][j]*10+pow(10, i-1);
	}
	string n=to_string(N);
	int len=n.size();
	int M=N;
	bool flag=false;
	if(len==1)
		ans[0]++;
	while(len){
		int idx=pow(10, len-1);
		int now=N/idx;
		if(!flag){
			if(now){
				for(int i=0;i<10;i++)
					ans[i]+=arr[len-1][i];
				for(int i=0;i<10;i++)
					ans[i]+=arr2[len-1][i]*(now-1);
				for(int i=1;i<now;i++)
					ans[i]+=idx;
			}
		}
		else{
			for(int i=0;i<10;i++)
				ans[i]+=arr2[len-1][i]*now;
			for(int i=0;i<now;i++)
				ans[i]+=idx;
		}
		
		ans[now]+=N%idx+1;

		flag=true;
		len--;
		N%=idx;
	}
	ans[0]--;
	for(int i=0;i<10;i++)
		printf("%lld ", ans[i]);
	printf("\n");
	return 0;
}

