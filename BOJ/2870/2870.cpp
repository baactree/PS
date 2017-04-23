// =====================================================================================
// 
//       Filename:  2870.cpp
//        Created:  2017년 04월 23일 20시 10분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> ans;
bool cmp(const string &a, const string &b){
	if(a.size()==b.size()){
		return a<b;
	}
	return a.size()<b.size();
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		str+="a";
		string now="";
		for(int i=0;i<str.size();i++){
			if(str[i]>='0'&&str[i]<='9'){
				now+=str[i];
			}
			else{
				if(now.size()>0)
					ans.push_back(now);
				now="";
			}
		}
	}
	for(int i=0;i<ans.size();i++){
		if(ans.size()==1||ans[i][0]!='0')
			continue;
		int idx=0;
		while(idx<ans[i].size()&&ans[i][idx]=='0')
			idx++;
		if(idx==ans[i].size()){
			ans[i]="0";
			continue;
		}
		ans[i]=string(ans[i].begin()+idx, ans[i].end());
	}
	sort(ans.begin(), ans.end(), cmp);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<'\n';
	return 0;
}

