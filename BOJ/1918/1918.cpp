// =====================================================================================
// 
//       Filename:  1918.cpp
//        Created:  2017년 01월 20일 17시 44분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

stack<char> st;
string arr;
int main(){
	cin>>arr;
	for(int i=0;i<arr.size();i++){
		if(arr[i]>='A'&&arr[i]<='Z')
			printf("%c", arr[i]);
		else {
			if(arr[i]=='('){
				st.push('(');
			}
			else if(arr[i]==')'){
				while(!st.empty()){
					char now = st.top();
					st.pop();
					if(now=='('){
						break;
					}
					printf("%c", now);
				}
			}
			else if(arr[i]=='+'||arr[i]=='-'){
				while(!st.empty()){
					char now = st.top();
					if(now=='('){
						break;
					}
					st.pop();
					printf("%c", now);
				}
				st.push(arr[i]);
			}
			else if(arr[i]=='*'||arr[i]=='/'){
				while(!st.empty()){
					char now = st.top();
					if(now=='*'||now=='/'){
						st.pop();
						printf("%c", now);
						continue;
					}
					break;
				}
				st.push(arr[i]);
			}
		}
	}
	while(!st.empty()){
		char now = st.top();
		st.pop();
		printf("%c", now);
	}
	printf("\n");
	return 0;
}

