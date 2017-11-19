#include <bits/stdc++.h>
using namespace std;
int main(){
	while(true){
		string str;
		getline(cin,str);
		if(str==".")
			break;
		stack<int> st;
		bool flag=true;
		for(int i=0;i<str.size();i++){
			if(str[i]=='(')
				st.push(0);
			if(str[i]=='[')
				st.push(1);
			if(str[i]==')'){
				if(st.empty()||st.top()!=0){
					flag=false;
					break;
				}
				st.pop();
			}
			if(str[i]==']'){
				if(st.empty()||st.top()!=1){
					flag=false;
					break;
				}
				st.pop();
			}
		}
		if(!st.empty())
			flag=false;
		printf("%s\n",flag?"yes":"no");
	}
	return 0;
}