// =====================================================================================
// 
//       Filename:  2464.cpp
//        Created:  2017년 06월 06일 17시 21분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a;
int n, m;
string now;
void print(const string &ans){
	ll out=0;
	ll r=1;
	for(int i=ans.size()-1;i>=0;i--){
		if(ans[i]=='1')
			out+=r;
		r*=2;
	}
	printf("%lld", out);
}
int main(){
	scanf("%lld", &a);	
	ll temp=a;
	n=62;
	now="";
	for(int i=0;i<n;i++){
		if(temp&1){
			m++;
			now+="1";
		}
		else
			now+="0";
		temp/=2;
	}
	reverse(now.begin(), now.end());
	string ans=now;
	if(prev_permutation(ans.begin(), ans.end())){
		print(ans);
	}
	else
		printf("0");
	printf(" ");
	ans=now;
	next_permutation(ans.begin(), ans.end());
	print(ans);
	printf("\n");
	return 0;
}

