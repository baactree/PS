// =====================================================================================
// 
//       Filename:  8892.cpp
//        Created:  2017년 03월 05일 17시 34분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string arr[100];
bool possi(const string &temp){
	int le=0;
	int ri=temp.size()-1;
	while(le<=ri){
		if(temp[le]==temp[ri]){
			le++;ri--;
		}
		else
			return false;
	}
	return true;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int k;
		scanf("%d", &k);
		for(int i=0;i<k;i++)
			cin>>arr[i];
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++){
				if(i==j)
					continue;
				string temp=arr[i]+arr[j];
				if(possi(temp)){
					cout<<temp<<'\n';
					goto next;
				}
			}
		printf("0\n");
		next:;
	}
	return 0;
}

