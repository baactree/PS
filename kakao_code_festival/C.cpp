// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 08월 05일 13시 28분 12초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string iv="invalid";
bool possi(int st, int ed, const string &str, vector<bool> &check){
	bool re=false;
	char retype=0;
	if((str[st]>='a'&&str[st]<='z')||(str[ed]>='a'&&str[ed]<='z'))
		return false;
	if(st+1<=ed&&str[st+1]>='a'&&str[st+1]<='z'){
		retype=str[st+1];
		if(check[retype-'a']){
			return false;
		}
		check[retype-'a']=true;
		int cnt=0;
		for(int i=st;i<=ed;i++){
			if(cnt&1){
				if(str[i]!=retype)
					return false;
			}
			else{
				if(str[i]>='a'&&str[i]<='z')
					return false;
			}
			cnt++;
		}
	}
	else{
		for(int i=st;i<=ed;i++)
			if(str[i]>='a'&&str[i]<='z')
				return false;
	}
	return true;
}
string solution(string str) {
    string ans = "";
	vector<bool> check(300, 0);
	for(int i=0;i<str.size();i++)
		if(str[i]==' '){
			while(true);
			return iv;
		}
	for(int i=0;i<str.size();i++){
		if(str[i]>='A'&&str[i]<='Z'){
			if(i+1==str.size()||(str[i+1]>='A'&&str[i+1]<='Z'))
				ans+=str[i];
			else{
				if(check[str[i+1]-'a'])
					return iv;
				char retype=str[i+1];
				int cnt=0;
				for(int j=i+2;j<str.size();j++)
					if(str[j]==retype)
						cnt++;
				if(cnt==0){
					if(i+2==str.size()||(str[i+2]>='a'&&str[i+2]<='z'))
						return iv;
					ans+=str[i];
					ans+=str[i+2];
					check[retype-'a']=true;
					i=i+2;
				}
				else if(cnt==1){
					ans+=str[i];
				}
				else{
					check[retype-'a']=true;
					cnt=0;
					int a,b;
					a=b=0;
					int j;
					for(j=i;j<str.size();j++){
						if(cnt&1){
							if(str[j]!=retype)
								break;
							a++;
						}
						else{
							if(str[j]>='A'&&str[j]<='Z'){
								ans+=str[j];
								b++;	
							}
							else
								return iv;
						}
						cnt++;
					}
					if(b!=a+1)
						return iv;
					i=j-1;
				}
			}
		}
		else{
			if(check[str[i]-'a'])
				return iv;
			check[str[i]-'a']=true;
			int next;
			for(next=i+1;next<str.size();next++){
				if(str[next]==str[i])
					break;
			}
			if(next==str.size())
				return iv;
			if(next==i+1)
				return iv;
			if(!possi(i+1, next-1, str, check))
				return iv;
			for(int j=i;j<=next;j++)
				if(str[j]>='A'&&str[j]<='Z')
					ans+=str[j];
			i=next;
		}
		ans+=" ";
	}
	while(!ans.empty()&&ans.back()==' ')
		ans.pop_back();
	while(ans[0]==' ');
	for(int i=0;i+1<ans.size();i++)
		if(ans[i]==' '&&ans[i+1]==' ')
			while(true);
    return ans;
}
int main(){
	string input;
	getline(cin, input);
	cout<<solution(input)<<endl;
	return 0;
}

