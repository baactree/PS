// =====================================================================================
// 
//       Filename:  1508.cpp
//        Created:  2017년 09월 18일 23시 44분 57초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int arr[50];
string possi(int x){
	for(int i=0;i<k;i++){
		int pre=i;
		string ret=string(i, '0')+"1";
		int cnt=1;
		for(int j=i+1;j<k;j++){
			if(arr[j]-arr[pre]>=x){
				if(cnt<m){
					ret+="1";
					cnt++;
					pre=j;
				}
				else
					ret+="0";
			}
			else{
				ret+="0";
			}
		}
		if(cnt==m&&ret.size()==k)
			return ret;
	}
	return "";
}
int main(){
	scanf("%d%d%d", &n, &m, &k);	
	for(int i=0;i<k;i++)
		scanf("%d", &arr[i]);
	if(m>=k){
		for(int i=0;i<k;i++)
			printf("1");
		printf("\n");
		return 0;
	}
	int le, ri, mid;
	le=1;
	ri=n;
	string ans="";
	while(le<=ri){
		mid=(le+ri)/2;
		string temp=possi(mid);
		if(temp.size()==k){
			ans=temp;
			le=mid+1;
		}
		else
			ri=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}

