// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 02월 24일 19시 11분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
string str1, str2;
int cnt[10];
int possi1(int d){
	int ret=0;
	memset(cnt, 0, sizeof(cnt));
	for(int i=0;i<n;i++)
		cnt[str2[i]-'0']++;
	for(int i=0;i<n;i++){
		bool flag=false;
		int idx;
		for(int j=str1[i]-'0';j<10;j++){
			if(cnt[j]){
				idx=j;
				flag=true;
				break;
			}
		}
		if(flag){
			cnt[idx]--;
			continue;
		}
		for(int j=0;j<str1[i]-'0';j++){
			if(cnt[j]){
				idx=j;
				flag=true;
				break;
			}
		}
		if(flag){
			cnt[idx]--;
			ret++;
			continue;
		}
	}
	return ret;
}

int possi2(int d){
	int ret=0;
	memset(cnt, 0, sizeof(cnt));
	for(int i=0;i<n;i++)
		cnt[str2[i]-'0']++;
	for(int i=0;i<n;i++){
		bool flag=false;
		int idx;
		for(int j=str1[i]-'0'+1;j<10;j++){
			if(cnt[j]){
				idx=j;
				flag=true;
				break;
			}
		}
		if(flag){
			cnt[idx]--;
			ret++;
			continue;
		}
		for(int j=0;j<=str1[i]-'0';j++){
			if(cnt[j]){
				idx=j;
				flag=true;
				break;
			}
		}
		if(flag){
			cnt[idx]--;
			continue;
		}
	}
	return ret;
}

int main(){
	cin>>n>>str1>>str2;
	int ans1, ans2;
	ans1=possi1(3);
	ans2=possi2(3);
	printf("%d\n%d\n", ans1, ans2);
	return 0;
}

