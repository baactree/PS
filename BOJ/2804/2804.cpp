// =====================================================================================
// 
//       Filename:  2804.cpp
//        Created:  2017년 03월 08일 20시 17분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string a, b;
int main(){
	cin>>a>>b;
	int aidx, bidx;
	int idx=0;
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++){
			if(a[i]==b[j]){
				aidx=i;
				bidx=j;
				goto next;
			}
		}
next:
	for(int i=0;i<b.size();i++){
		if(i==bidx){
			cout<<a<<endl;
			idx++;
			continue;
		}
		for(int j=0;j<a.size();j++){
			if(j==aidx){
				printf("%c", b[idx++]);
			}
			else
				printf("%c", '.');
		}
		printf("\n");
	}
	return 0;
}

