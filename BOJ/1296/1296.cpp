// =====================================================================================
// 
//       Filename:  1296.cpp
//        Created:  2017년 05월 08일 16시 05분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int n;
vector<int> cnt(300, 0);
int main(){
	cin>>str>>n;
	for(int i=0;i<str.size();i++)
		cnt[str[i]]++;
	string ans=string(20, 'Z');
	int max_value=-1;
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		vector<int> ncnt=cnt;
		for(int j=0;j<temp.size();j++)
			ncnt[temp[j]]++;
		int now=(ncnt['L']+ncnt['O'])*(ncnt['L']+ncnt['V'])*(ncnt['L']+ncnt['E'])*(ncnt['O']+ncnt['V'])*(ncnt['O']+ncnt['E'])*(ncnt['V']+ncnt['E']);
		now%=100;
		if(max_value<now){
			max_value=now;
			ans=temp;
		}
		else if(max_value==now){
			ans=min(ans, temp);
		}
	}
	cout<<ans<<endl;
	return 0;
}

