// =====================================================================================
// 
//       Filename:  3012.cpp
//        Created:  2017년 08월 11일 21시 34분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string str;
pair<ll, int> cache[200][200];
const int mod=1e5;
bool flag;
pair<ll, int> solve(int le, int ri){
	int sz=ri-le+1;
	if(sz&1)
		return {0ll, 0};
	if(le==ri+1)
		return {1ll, 0};
	if(le>ri+1)
		return {0ll, 0};
	pair<ll, int> &ret=cache[le][ri];
	if(ret!=make_pair(-1ll, 0))
		return ret;
	ret={0ll, 0};
	if(str[le]=='?'){
		if(str[ri]=='?'){
			auto temp=solve(le+1, ri-1);
			ret.first=(ret.first+temp.first*3);
			ret.second|=temp.second;
		}
		else if(str[ri]==')'||str[ri]=='}'||str[ri]==']'){
			auto temp=solve(le+1, ri-1);
			ret.first=(ret.first+temp.first);
			ret.second|=temp.second;
		}
	}
	else if(str[ri]=='?'){
		if(str[le]=='('||str[le]=='{'||str[le]=='['){
			auto temp=solve(le+1, ri-1);
			ret.first=(ret.first+temp.first);
			ret.second|=temp.second;
		}
	}
	else{
		if(str[le]=='('&&str[ri]==')'){
			auto temp=solve(le+1, ri-1);
			ret.first=(ret.first+temp.first);
			ret.second|=temp.second;
		}
		if(str[le]=='{'&&str[ri]=='}'){
			auto temp=solve(le+1, ri-1);
			ret.first=(ret.first+temp.first);
			ret.second|=temp.second;
		}
		if(str[le]=='['&&str[ri]==']'){
			auto temp=solve(le+1, ri-1);
			ret.first=(ret.first+temp.first);
			ret.second|=temp.second;
		}
	}
	if(ret.first>=mod){
		ret.first%=mod;
		ret.second=true;
	}
	for(int i=le+1;i<ri-1;i+=2){
		ret.first=(ret.first+solve(le, i).first*solve(i+1, ri).first);
		if(solve(le, i)!=make_pair(0ll, 0)&&solve(i+1, ri)!=make_pair(0ll, 0)){
			ret.second|=solve(le, i).second;
			ret.second|=solve(i+1, ri).second;
		}
		if(ret.first>=mod){
			ret.first%=mod;
			ret.second=true;
		}
	}
	return ret;
}
int main(){
	for(int i=0;i<200;i++)
		for(int j=0;j<200;j++)
			cache[i][j]={-1ll, 0};
	cin>>n>>str;
	if(n&1)
		return !printf("0\n");
	auto ans=solve(0, n-1);
	if(ans.first>=1e5||ans.second){
		ans.first%=100000;
		printf("%05lld\n", ans.first);
	}
	else
		printf("%lld\n", ans.first);
	return 0;
}

