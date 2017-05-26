// =====================================================================================
// 
//       Filename:  2469.cpp
//        Created:  2017년 05월 26일 19시 07분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k, n;
char mat[1000][30];
int m;
string fi;
int main(){
	scanf("%d%d", &k, &n);
	cin>>fi;
	for(int i=0;i<n;i++){
		scanf("%s", mat[i]);
		if(mat[i][0]=='?')
			m=i;
	}
	string st="";
	for(int i=0;i<k;i++)
		st+=(char)(i+'A');
	for(int i=0;i<m;i++){
		for(int j=0;j<k-1;j++)
			if(mat[i][j]=='-')
				swap(st[j], st[j+1]);
	}
	for(int i=n-1;i>m;i--)
		for(int j=0;j<k-1;j++)
			if(mat[i][j]=='-')
				swap(fi[j], fi[j+1]);
	string ans="";
	string im="";
	for(int i=0;i<k-1;i++)
		im+="x";
	for(int i=0;i<k;i++)
		if(st[i]==fi[i])
			ans+="*";
		else{
			if(i==k-1||st[i]!=fi[i+1]){
				cout<<im<<endl;
				return 0;
			}
			ans+="-*";
			i++;
		}
	ans.pop_back();
	cout<<ans<<endl;
	return 0;
}

