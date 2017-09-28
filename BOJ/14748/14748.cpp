// =====================================================================================
// 
//       Filename:  14748.cpp
//        Created:  2017년 09월 28일 17시 07분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int w;
string str;
bool chk[300];
int solve(){
	string temp="";
	for(int i=0;i<str.size();i++){
		if(!chk[str[i]])
			return -1;
		if(str[i]==' ')
			continue;
		temp+=str[i];
	}
	str=temp;
	stack<int> st;
	for(int i=0;i<str.size();i++){
		if(str[i]=='('||str[i]=='[')
			st.push(i);
		else if(str[i]==')'||str[i]==']'){
			if(st.empty())
				return -1;
			int idx=st.top();
			st.pop();
			if(str[i]==')'&&str[idx]=='(')
				continue;
			if(str[i]==']'&&str[idx]=='[')
				continue;
			return -1;
		}
	}
	if(!st.empty())
		return -1;
	for(int i=0;i+1<str.size();i++){
		if(str[i]==',')
			if(!(str[i+1]=='B'||str[i+1]=='L'||str[i+1]=='S'))
				return -1;
		if(str[i]=='S')
			if(!(str[i+1]==','||str[i+1]==']'||str[i+1]==')'))
				return -1;
		if(str[i]=='L')
			if(!(str[i+1]=='('||str[i+1]=='['))
				return -1;
		if(str[i]=='B')
			if(!(str[i+1]=='('||str[i+1]=='['))
				return -1;
		if(str[i]=='(')
			if(!(str[i+1]=='B'||str[i+1]=='L'||str[i+1]=='S'))
				return -1;
		if(str[i]=='[')
			if(!(str[i+1]=='B'||str[i+1]=='L'||str[i+1]=='S'))
				return -1;
		if(str[i]==')')
			if(!(str[i+1]==')'||str[i+1]==']'||str[i+1]==','))
				return -1;
		if(str[i]==']')
			if(!(str[i+1]==')'||str[i+1]==']'||str[i+1]==','))
				return -1;
	}
	if(!(str.back()=='S'||str.back()==']'||str.back()==')'))
		return -1;
	int b, l, s;
	b=l=s=0;
	for(int i=0;i<str.size();i++){
		if(str[i]=='B')
			b++;
		if(str[i]=='L')
			l++;
		if(str[i]=='S')
			s++;
	}
	int v=s+b*2+l*2;
	int be=l;
	int fe=v-1+b;
	return fe+be*w-v+2;
}
int main(){
	chk['S']=chk['L']=chk['B']=chk[',']=chk['(']
		=chk[')']=chk['[']=chk[']']=chk[' ']=true;
	scanf("%d\n", &w);
	getline(cin, str);
	printf("%d\n", solve());
	return 0;
}

