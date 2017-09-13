// =====================================================================================
// 
//       Filename:  11531.cpp
//        Created:  2017년 09월 13일 22시 25분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int cnt[105];
bool chk[105];
int main(){
	int ans=0;
	int k=0;
	while(true){
		int a;
		cin>>a;
		if(a==-1)
			break;
		string b, c;
		cin>>b>>c;
		if(c=="wrong"){
			cnt[b[0]-'A']++;
		}
		else{
			if(!chk[b[0]-'A']){
				k++;
				chk[b[0]-'A']=true;
				ans+=a+cnt[b[0]-'A']*20;
			}
		}
	}
	printf("%d %d\n", k, ans);
	return 0;
}

