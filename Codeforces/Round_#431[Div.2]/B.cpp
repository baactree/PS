// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 09월 15일 22시 15분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000];
bool chk[1000];
typedef long long ll;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	for(int i=1;i<n;i++){
			ll a, b;
			a=(arr[i]-arr[0]);
			b=i;
			memset(chk, 0, sizeof(chk));
			chk[0]=true;
			for(int j=1;j<n;j++)
				if((arr[j]-arr[0])*b==a*j){
					chk[j]=true;
				}
			int st=-1;
			for(int j=1;j<n;j++)
				if(!chk[j]){
					st=j;
					break;
				}
			if(st==-1)
				continue;
			chk[st]=true;
			for(int j=st+1;j<n;j++)
				if((arr[j]-arr[st])*b==a*(j-st))
					chk[j]=true;
			bool flag=false;
			for(int j=0;j<n;j++)
				if(!chk[j])
					flag=true;
			if(!flag)
				return !printf("Yes\n");
	}
	int d=arr[2]-arr[1];
	if(arr[1]-arr[0]==d)
		return !printf("No");
	bool flag=false;
	for(int i=2;i<n;i++){
		if((arr[i]-arr[1])/(i-1)!=d)
			flag=true;
	}
	printf("%s\n", flag?"No":"Yes");
	return 0;
}

