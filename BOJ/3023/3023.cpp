// =====================================================================================
// 
//       Filename:  3023.cpp
//        Created:  2017년 03월 01일 20시 26분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string arr[100];
int r, c;
int main(){
	scanf("%d%d", &r, &c);
	for(int i=0;i<r;i++){
		cin>>arr[i];
		string temp=arr[i];
		reverse(temp.begin(), temp.end());
		arr[i]=arr[i]+temp;
		arr[2*r-1-i]=arr[i];
	}
	int a, b;
	scanf("%d%d", &a, &b);
	a--;b--;
	if(arr[a][b]=='.')
		arr[a][b]='#';
	else
		arr[a][b]='.';
	for(int i=0;i<2*r;i++)
		cout<<arr[i]<<'\n';
	return 0;
}

