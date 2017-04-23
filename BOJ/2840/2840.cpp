// =====================================================================================
// 
//       Filename:  2840.cpp
//        Created:  2017년 04월 21일 13시 01분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char ans[25];
int n, k;
pair<int, char> arr[100];
int cnt[26];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		ans[i]='?';
	for(int i=0;i<k;i++){
		char in[2];
		scanf("%d%s", &arr[i].first, in);
		arr[i].second=in[0];
	}
	int now=0;
	for(int i=k-1;i>=0;i--){
		if(ans[now]=='?'){
			ans[now]=arr[i].second;
			now=(now+arr[i].first)%n;
		}
		else if(ans[now]==arr[i].second){
			now=(now+arr[i].first)%n;
		}
		else{
			printf("!\n");
			return 0;
		}
	}
	
	for(int i=0;i<n;i++){
		cnt[ans[i]-'A']++;
	}
	if(*max_element(cnt, cnt+26)>1){
		printf("!\n");
		return 0;
	}
	for(int i=0;i<n;i++)
		printf("%c", ans[i]);
	printf("\n");
	return 0;
}

