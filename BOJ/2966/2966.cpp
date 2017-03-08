// =====================================================================================
// 
//       Filename:  2966.cpp
//        Created:  2017년 03월 08일 22시 06분 52초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
string ans;
int s, c, h;
int main(){
	cin>>n>>ans;
	for(int i=0;i<n;i++){
		if(i%3==0){
			if(ans[i]=='A')
				s++;
		}
		else if(i%3==1){
			if(ans[i]=='B')
				s++;
		}
		else{
			if(ans[i]=='C')
				s++;
		}

		if(i%2==0){
			if(ans[i]=='B')
				c++;
		}
		else{
			if((i/2)%2==0){
				if(ans[i]=='A')
					c++;
			}
			else
				if(ans[i]=='C')
					c++;
		}

		if((i/2)%3==0){
			if(ans[i]=='C')
				h++;
		}	
		else if((i/2)%3==1){
			if(ans[i]=='A')
				h++;
		}
		else{
			if(ans[i]=='B')
				h++;
		}
	}
	int max_value=-1;
	max_value=max(max_value, s);
	max_value=max(max_value, c);
	max_value=max(max_value, h);
	printf("%d\n", max_value);
	if(max_value==s){
		printf("Adrian\n");
	}
	if(max_value==c){
		printf("Bruno\n");
	}
	if(max_value==h){
		printf("Goran\n");
	}
	return 0;
}

