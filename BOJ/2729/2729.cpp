// =====================================================================================
// 
//       Filename:  2729.cpp
//        Created:  2017년 03월 22일 14시 34분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		string a, b, ans;
		cin>>a>>b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		if(a.size()>b.size())
			swap(a, b);
		int carry=0;
		ans="";
		for(int i=0;i<a.size();i++){
			int now=a[i]-'0'+b[i]-'0'+carry;
			if(now>1){
				now-=2;
				carry=1;
			}
			else{
				carry=0;
			}
			ans+=(char)(now+'0');
		}
		for(int i=a.size();i<b.size();i++){
			int now=b[i]-'0'+carry;
			if(now>1){
				now-=2;
				carry=1;
			}
			else
				carry=0;
			ans+=(char)(now+'0');
		}
		if(carry){
			ans+='1';
		}
		while(ans.size()!=1&&ans.back()=='0')
			ans.pop_back();
		reverse(ans.begin(), ans.end());
		cout<<ans<<'\n';
	}
	return 0;
}

