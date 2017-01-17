// =====================================================================================
// 
//       Filename:  8595.cpp
//        Created:  2017년 01월 17일 15시 04분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
string arr;
long long solve(string arr){
	long long ret=0;
	int now=0;
	int cnt=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]>='0'&&arr[i]<='9'){
			cnt++;
			now*=10;
			now+=arr[i]-'0';
			if(cnt>6){
				cnt=0;
				now=0;
			}
		}
		else{
			ret+=now;
			cnt=0;
			now=0;
		}
	}
	ret+=now;
	return ret;
}
int main(){
	cin>>n>>arr;
	printf("%lld\n", solve(arr));
	return 0;
}

