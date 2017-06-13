// =====================================================================================
// 
//       Filename:  2257.cpp
//        Created:  2017년 06월 14일 00시 39분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
string c;
string s;
int main(){
	cin>>str;
	c=str[0];
	for(int i=1;i<str.size();i++){
		if(str[i]=='H'||str[i]=='C'||str[i]=='O'){
			if(str[i-1]!='(')
				c+="+";
			c+=str[i];
		}
		else if(str[i]=='('||str[i]==')'){
			if(str[i]!=')'&&str[i-1]!='(')
				c+="+";
			c+=str[i];
		}
		else if(str[i]>='2'&&str[i]<='9'){
			if(str[i-1]!='(')
				c+="*";
			c+=str[i];
		}
	}
	stack<int> st;
	for(int i=0;i<c.size();i++){
		if(c[i]=='H'||c[i]=='C'||c[i]=='O'||(c[i]>='2'&&c[i]<='9'))
			s+=c[i];
		else{
			if(c[i]=='(')
				st.push('(');
			else if(c[i]==')'){
				while(!st.empty()){
					char now=st.top();
					st.pop();
					if(now=='(')
						break;
					s+=now;
				}
			}
			else if(c[i]=='+'){
				while(!st.empty()){
					char now=st.top();
					if(now=='(')
						break;
					st.pop();
					s+=now;
				}
				st.push(c[i]);
			}
			else if(c[i]=='*'){
				while(!st.empty()){
					char now=st.top();
					if(now=='*'){
						st.pop();
						s+=now;
						continue;
					}
					break;
				}
				st.push(c[i]);
			}
		}
	}
	while(!st.empty()){
		char now=st.top();
		st.pop();
		s+=now;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='H'){
			st.push(1);
		}
		else if(s[i]=='C'){
			st.push(12);
		}
		else if(s[i]=='O'){
			st.push(16);
		}
		else if(s[i]>='2'&&s[i]<='9'){
			st.push(s[i]-'0');
		}
		else if(s[i]=='+'){
			
			int a=0;
			if(!st.empty()){
				a=st.top();
				st.pop();
			}
			int b=0;
			if(!st.empty()){
				b=st.top();
				st.pop();
			}
			st.push(a+b);
		}
		else if(s[i]=='*'){
			int a=0;
			if(!st.empty()){
				a=st.top();
				st.pop();
			}
			int b=0;
			if(!st.empty()){
				b=st.top();
				st.pop();
			}
			st.push(a*b);
		}
	}
	printf("%d\n", st.top());
	return 0;
}

