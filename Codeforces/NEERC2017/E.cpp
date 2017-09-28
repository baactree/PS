// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 09월 23일 01시 31분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
string str;
bool possi(int x){
	vector<int> s, p;
	for(int i=0;i<str.size();i++)
		if(str[i]=='*')
			s.push_back(i);
		else if(str[i]=='P')
			p.push_back(i);
	int idx=0;
	for(int i=0;i<p.size();i++){
		int loc=p[i];
		if(idx==s.size())
			return true;
		if(s[idx]>loc){
			while(idx<s.size()&&s[idx]-loc<=x)
				idx++;
		}
		else{
			if(loc-s[idx]<=x){
				int r=x-(loc-s[idx])*2;
				int r2=x-(loc-s[idx]);
				while(idx<s.size()&&s[idx]<loc)
					idx++;
				if(idx==s.size())
					return true;
				while(idx<s.size()&&(s[idx]-loc<=r||(s[idx]-loc)*2<=r2))
					idx++;
			}
		}
	}
	return idx==s.size();
}
int main(){
	cin>>n>>str;
	int le, ri, mid, ans;
	le=0;
	ri=2*n;
	ans=-1;
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

