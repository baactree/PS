// =====================================================================================
// 
//       Filename:  2800.cpp
//        Created:  2017년 08월 03일 01시 18분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int check[300];
int main(){
	cin>>str;
	int cnt=0;
	stack<int> st;
	memset(check, -1, sizeof(check));
	for(int i=0;i<str.size();i++){
		if(str[i]=='('){
			st.push(i);
			check[i]=cnt++;
		}
		else if(str[i]==')'){
			int now=st.top();
			st.pop();
			check[i]=check[now];
		}
	}
	vector<string> ans;
	for(int i=1;i<(1<<cnt);i++){
		string now="";
		for(int j=0;j<str.size();j++){
			if(str[j]=='('||str[j]==')'){
				if(i&(1<<check[j]))
					continue;
			}
			now+=str[j];
		}
		ans.push_back(now);
	}
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++){
		if(i!=0&&ans[i]==ans[i-1])
			continue;
		cout<<ans[i]<<'\n';
	}
	return 0;
}

