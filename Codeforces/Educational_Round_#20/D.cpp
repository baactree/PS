// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 04월 29일 00시 30분 44초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k;
char str[10000005];
char temp[10000005];
int n;
vector<int> in;
bool possi(int x){
	int cnt=0;
	int p=1;
	for(int i=0;i<n;i++){
		int t=(i!=n-1);
		if(cnt+in[i]+t<=x)
			cnt+=in[i]+t;
		else if(in[i]+t>x){
			return false;
		}
		else{
			p++;
			cnt=in[i]+t;
		}
	}
	return p<=k;
}
int main(){
	scanf("%d\n", &k);
	gets(str);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]=='-')
			str[i]=' ';
		if(str[i]==' ')
			n++;
	}
	n++;
	int idx=0;
	for(int i=0;i<n;i++){
		sscanf(str+idx, "%s", temp);
		in.push_back(strlen(temp));
		idx+=strlen(temp)+1;
	}
	int le, ri, mid;
	int ans;
	le=1;ri=1e9;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	printf("%d\n", ans);
	return 0;
}

