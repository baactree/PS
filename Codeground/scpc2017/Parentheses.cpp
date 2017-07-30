// =====================================================================================
// 
//       Filename:  Parentheses.cpp
//        Created:  2017년 07월 01일 00시 05분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

char str[1000005];
int len;
int main(){
	int testcase;
	scanf("%d",&testcase);
	for(int tc=1;tc<=testcase;tc++){
		scanf("%s",str);
		len=strlen(str);
		stack<pair<int,int> > st;
		st.push(make_pair(-1,-1));
		int ans=0;
		for(int i=0;i<len;i++){
			if(str[i]=='('){
				st.push(make_pair(0,i));
			}
			else if(str[i]=='{'){
				st.push(make_pair(1,i));
			}
			else if(str[i]=='['){
				st.push(make_pair(2,i));
			}
			else if(str[i]==')'){
				if(st.top().first==0){
					st.pop();
					if(!st.empty())
						ans=max(ans,i-st.top().second);
				}
				else{
					st=stack<pair<int,int> >();
					st.push(make_pair(-1,i));
				}
			}
			else if(str[i]=='}'){
				if(st.top().first==1){
					st.pop();
					if(!st.empty())
						ans=max(ans,i-st.top().second);
				}
				else{
					st=stack<pair<int,int> >();
					st.push(make_pair(-1,i));
				}
			}
			else{
				if(st.top().first==2){
					st.pop();
					if(!st.empty())
						ans=max(ans,i-st.top().second);
				}
				else{
					st=stack<pair<int,int> >();
					st.push(make_pair(-1,i));
				}
			}
		}
		printf("Case #%d\n",tc);
		printf("%d\n",ans);
	}
	return 0;
}

