// =====================================================================================
// 
//       Filename:  4388.cpp
//        Created:  2017년 03월 12일 18시 24분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	while(true){
		string a, b;
		cin>>a>>b;
		if(a=="0"&&b=="0")
			break;
		if(a.size()>b.size())
			swap(a, b);
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int ans=0;
		int carry=0;
		for(int i=0;i<b.size();i++){
			if(i<a.size()){
				if(carry+a[i]-'0'+b[i]-'0'>9){
					ans++;
					carry=1;
				}
				else
					carry=0;
			}
			else{
				if(carry+b[i]-'0'>9){
					ans++;
					carry=1;
				}
				else
					carry=0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

