// =====================================================================================
// 
//       Filename:  1935.cpp
//        Created:  2017년 03월 22일 14시 02분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[26];
string str;
int n;
int main(){
	scanf("%d", &n);
	cin>>str;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	stack<double> st;
	for(int i=0;i<str.size();i++){
		if(str[i]>='A'&str[i]<='Z'){
			st.push(arr[str[i]-'A']);
		}
		else{
			double a=st.top();
			st.pop();
			double b=st.top();
			st.pop();
			if(str[i]=='*'){
				st.push(b*a);
			}
			if(str[i]=='/'){
				st.push(b/a);
			}
			if(str[i]=='+'){
				st.push(b+a);
			}
			if(str[i]=='-'){
				st.push(b-a);
			}
		}
	}
	printf("%.2lf\n", st.top());
	return 0;
}

