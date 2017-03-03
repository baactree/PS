// =====================================================================================
// 
//       Filename:  1339.cpp
//        Created:  2017년 02월 25일 20시 13분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
string str;
pair<int, int> cnt[26];
int main(){
	for(int i=0;i<26;i++)
		cnt[i].second=i;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		cin>>str;
		int x=1;
		for(int i=str.size()-1;i>=0;i--){
			cnt[str[i]-'A'].first+=x;
			x*=10;
		}
	}
	long long ans=0;
	sort(cnt, cnt+26);
	int counter=9;
	for(int i=25;i>=0;i--){
		ans+=cnt[i].first*counter;
		counter--;
		if(counter==0)
			break;
	}
	printf("%lld\n", ans);
	return 0;
}

