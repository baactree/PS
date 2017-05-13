// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 05월 13일 18시 49분 16초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string a, b;
multiset<char> as, bs;
char ans[300005];
int main(){
	cin>>a>>b;
	int n=a.size();
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	a=string(a.begin(), a.begin()+(a.size()+1)/2);
	b=string(b.begin()+(b.size()/2+(n&1)), b.end());
	reverse(b.begin(), b.end());
	for(int i=0;i<a.size();i++)
		as.insert(a[i]);
	for(int i=0;i<b.size();i++)
		bs.insert(b[i]);
	int f=0;
	int b=n-1;
	for(int i=0;i<n;i++){
		if(i&1){
			char now=*(--bs.end());
			char back=*as.begin();
			if(now<=back){
				now=*bs.begin();
				ans[b]=now;
				b--;
				bs.erase(bs.begin());
			}
			else{
				ans[f]=now;
				f++;
				bs.erase(--bs.end());
			}
		}
		else{
			if(bs.empty()){
				ans[f]=*as.begin();
				break;
			}
			char now=*as.begin();
			char back=*(--bs.end());
			if(now>=back){
				now=*(--as.end());
				ans[b]=now;
				b--;
				as.erase(--as.end());
			}
			else{
				ans[f]=now;
				f++;
				as.erase(as.begin());
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

