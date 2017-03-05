// =====================================================================================
// 
//       Filename:  13413.cpp
//        Created:  2017년 03월 05일 18시 19분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char st[100005];
char fi[100005];
int n;
void order2(int cnt){
	if(cnt<0){
		for(int i=0;i<n&&cnt!=0;i++){
			if(fi[i]=='B'&&st[i]!='B'){
				st[i]='B';
				cnt++;
			}
		}
	}
	else{
		for(int i=0;i<n&&cnt!=0;i++){
			if(st[i]=='B'&&fi[i]!='B'){
				st[i]='W';
				cnt--;
			}
		}
	}
}
int order1(){
	int cnt=0;
	for(int i=0;i<n;i++)
		if(st[i]!=fi[i])
			cnt++;
	return cnt/2;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d", &n);
		scanf("%s%s", st, fi);
		int cnt=0;
		for(int i=0;i<n;i++)
			if(st[i]=='B')
				cnt++;
		for(int i=0;i<n;i++)
			if(fi[i]=='B')
				cnt--;
		int ans=0;
		if(cnt!=0){
			ans=abs(cnt);
			order2(cnt);
		}
		ans+=order1();
		printf("%d\n", ans);
	}
	return 0;
}

